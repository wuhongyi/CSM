// AutomaticSearch.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 10月  2 13:57:12 2016 (+0800)
// Last-Updated: 日 10月  2 14:26:51 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 6
// URL: http://wuhongyi.github.io 

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <cfloat>
#include <cmath>
#include "wuReadData.hh"
# define LENGTH 100
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// LineStyle：
// 1=solid   2=dash   3=dot   4=dash-dot

void dealpsk(char *filename,int selectlinestyle, int *linestyle,double *x_min,double *y_min,double *y_init)
{
  std::ifstream infile;
  std::string onelinestring;
  
  double xxx[22] = {0.0,0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,0.95,1.0,1.05};
  double y0[2];
  double rawdata[22][4];
  int LineStyle;// 1=solid   2=dash   3=dot   4=dash-dot
  
  int FlagLineStyle[LENGTH];
  double FlagY0[LENGTH];
  double data[LENGTH][44];
  bool flagcouple[LENGTH];

  
  int flag;
  flag = 0;
	    
  infile.open(filename);
  if(infile.fail())
    {
      std::cout<<"Can't open the file : "<<infile<<". Please check it."<<std::endl;
    }


  while(getline(infile,onelinestring))
    {
      // cout<<onelinestring.size()<<"|"<<onelinestring<<endl;
      if(onelinestring.size() == 13 && onelinestring[1] == 'L' && onelinestring[6] == 'S') break;
    }

  for (int ii = 0; ii < LENGTH; ++ii)
    {
      flagcouple[ii] = false;
      FlagLineStyle[ii] = 0;
      FlagY0[ii] = 0;	    
    }
		
  while(!infile.eof())
    {
		
      getline(infile,onelinestring);
      if(infile.eof()) break;//避免最后一个重复读取
      if(onelinestring[9] == 'I') LineStyle = 1;
      if(onelinestring[9] == 'H') LineStyle = 2;
      if(onelinestring[9] == 'T') LineStyle = 3;
      if(onelinestring[9] == 'D') LineStyle = 4;
      // cout<<"LineStyle: "<<LineStyle<<endl;
      getline(infile,onelinestring);// DATA
      // cout<<onelinestring<<endl;
      infile>>y0[0]>>y0[1];getline(infile,onelinestring);
      // cout<<y0[0]<<" "<<y0[1]<<endl;
      for (int ii = 0; ii < 22; ++ii)
	{
	  infile>>rawdata[ii][0]>>rawdata[ii][1]>>rawdata[ii][2]>>rawdata[ii][3];
	  getline(infile,onelinestring);
	  // cout<<rawdata[ii][0]<<" "<<rawdata[ii][1]<<" "<<rawdata[ii][2]<<" "<<rawdata[ii][3]<<endl;
	}
				
      if(y0[1] > 0)
	{
	  FlagLineStyle[flag] = LineStyle;
	  // cout<<"LineStyle: "<<FlagLineStyle[flag]<<"  "<<flag<<endl;
	  FlagY0[flag] = y0[1];
	  for (int ii = 0; ii < 22; ++ii) data[flag][ii] = rawdata[ii][1];		    
	  flag++;
	  // cout<<flag<<endl;
	}
      else
	{
	  // cout<<"LineStyle: "<<LineStyle<<endl;
	  for (int ii = 0; ii < flag; ++ii)
	    {
	      // cout<<flag<<"  "<<flagcouple[ii]<<" "<<FlagLineStyle[ii]<<endl;
	      if(flagcouple[ii] == false && FlagLineStyle[ii] == LineStyle && std::abs(FlagY0[ii]+y0[1]) < 1e-3)//正负配对的起始相等判据  有的相差 1e-4
		{
		  // cout<<"@@@@@@@@@@@@@@"<<ii<<endl;
		  for (int jj = 0; jj < 22; ++jj) data[ii][jj+22] = rawdata[jj][1];
		  flagcouple[ii] = true;
		}
			
	    }
		    
	}

    }//一个文件读取结束
  infile.close();

  // =============
  
  // cout<<flag<<endl;
  // for (int ii = 0; ii < flag; ++ii)
  //   {
  //     if(flagcouple[ii] == true)
  // 	{
  // 	  cout<<FlagLineStyle[ii]<<"  ";
  // 	  for (int jj = 0; jj < 22; ++jj)
  // 	    cout<<data[ii][jj]<<" ";
  // 	  cout<<endl;

  // 	  cout<<"  ";
  // 	  for (int jj = 0; jj < 22; ++jj)
  // 	    cout<<data[ii][jj+22]<<" ";
  // 	  cout<<endl;
  // 	}
  //   }

  // =============
  
  int flagxmin;
  double tempdouble;
  int tempxmin = -1;
  int flagii;

  flagxmin = 22;
  for (int ii = 0; ii < flag; ++ii)
    {
      
      if(flagcouple[ii] == true && FlagLineStyle[ii] == selectlinestyle)
	{
	  tempdouble = DBL_MAX;//设置成很大
	  for (int jj = 0; jj < 22; ++jj)
	    {
	      if(std::abs(data[ii][jj]-data[ii][jj+22]) < tempdouble)
		{
		  tempdouble = std::abs(data[ii][jj]-data[ii][jj+22]);
		  tempxmin = jj;
		}
	    }

	  if(tempdouble < 3)//这个是经验数值
	  if(tempxmin < flagxmin)
	    {
	      flagxmin = tempxmin;
	      flagii = ii;
	      *y_min = tempdouble;
	    }	  
	}
    }
	    
  *linestyle = FlagLineStyle[flagii];
  *x_min = xxx[flagxmin];
  *y_init = FlagY0[flagii];

  cout<<*linestyle<<"  "<<*x_min<<"  "<<*y_min<<"  "<<*y_init<<endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc, char *argv[])
{
  std::string inputcardfilename = "input.txt";
  std::string outputdir = wuReadData::ReadValue<std::string>("outputdir",inputcardfilename);//输出文件夹，结尾不能出现 \
  
  double BETA2_bin = wuReadData::ReadValue<double>("BETA2_bin",inputcardfilename);
  double BETA2_min = wuReadData::ReadValue<double>("BETA2_min",inputcardfilename);
  double BETA2_max = wuReadData::ReadValue<double>("BETA2_max",inputcardfilename);
  double BETA4_bin = wuReadData::ReadValue<double>("BETA4_bin",inputcardfilename);
  double BETA4_min = wuReadData::ReadValue<double>("BETA4_min",inputcardfilename);
  double BETA4_max = wuReadData::ReadValue<double>("BETA4_max",inputcardfilename);
  double GAMM_bin = wuReadData::ReadValue<double>("GAMM_bin",inputcardfilename);
  double GAMM_min = wuReadData::ReadValue<double>("GAMM_min",inputcardfilename);
  double GAMM_max = wuReadData::ReadValue<double>("GAMM_max",inputcardfilename);

  int SelectLinesStyle = wuReadData::ReadValue<int>("LineStyle",inputcardfilename);
  
  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  
  char filename[128];

  int linestyle;
  double x_min;
  double y_min;
  double y_init;

  std::ofstream writeN;//fstream
  sprintf(filename,"%s/n.txt",outputdir.c_str());
  writeN.open(filename);//ios::bin ios::app
  if(writeN.fail())
    {
      std::cout<<"can't open file"<<std::endl;
    }

  writeN<<"BETA2 BETA4 GAMMA Wc y_min y(0) LineStyle"<<endl;
    
  std::ofstream writeP;//fstream
  sprintf(filename,"%s/p.txt",outputdir.c_str());
  writeP.open(filename);//ios::bin ios::app
  if(writeP.fail())
    {
      std::cout<<"can't open file"<<std::endl;
    } 
  writeP<<"BETA2 BETA4 GAMMA Wc y_min y(0) LineStyle"<<endl;

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  
  for(double i=BETA2_min;i<=BETA2_max;i+=BETA2_bin)
    for(double j=BETA4_min;j<=BETA4_max;j+=BETA4_bin)
      {
	
	for(double  k=GAMM_min;k<=GAMM_max;k+=GAMM_bin)
	  {
	    sprintf(filename,"%s/%f_%f_%f/input_N.psk",outputdir.c_str(),i,j,k);
	    cout<<i<<" "<<j<<" "<<k<<endl;
	    dealpsk(filename,SelectLinesStyle, &linestyle,&x_min,&y_min,&y_init);
	    writeN<<i<<" "<<j<<" "<<k<<" "<<x_min<<" "<<y_min<<" "<<y_init<<" "<<linestyle<<endl;

	    sprintf(filename,"%s/%f_%f_%f/input_P.psk",outputdir.c_str(),i,j,k);
	    dealpsk(filename,SelectLinesStyle, &linestyle,&x_min,&y_min,&y_init);
	    writeP<<i<<" "<<j<<" "<<k<<" "<<x_min<<" "<<y_min<<" "<<y_init<<" "<<linestyle<<endl;
	    

	  }//k
      }// i j

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  writeN.close();
  writeP.close();

  
  return 0;
}

// 
// AutomaticSearch.cc ends here
