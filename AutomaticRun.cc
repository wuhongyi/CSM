// AutomaticRun.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 10月  2 13:11:55 2016 (+0800)
// Last-Updated: 二 10月  4 14:16:14 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 6
// URL: http://wuhongyi.cn 

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include "wuReadData.hh"
using namespace std;

int main(int argc, char *argv[])
{

  std::string inputcardfilename = "input.txt";
  std::string outputdir = wuReadData::ReadValue<std::string>("outputdir",inputcardfilename);//输出文件夹，结尾不能出现 \

  // 以下参数为输入卡swgamma.inp
  char swgammafilename[128] = "swgamma.inp";
  int INTDAT_IAUTO = wuReadData::ReadValue<int>("INTDAT_IAUTO",inputcardfilename);
  int NAZWIS = wuReadData::ReadValue<int>("NAZWIS",inputcardfilename);
  double BETA2_bin = wuReadData::ReadValue<double>("BETA2_bin",inputcardfilename);
  double BETA2_min = wuReadData::ReadValue<double>("BETA2_min",inputcardfilename);
  double BETA2_max = wuReadData::ReadValue<double>("BETA2_max",inputcardfilename);
  double BETA4_bin = wuReadData::ReadValue<double>("BETA4_bin",inputcardfilename);
  double BETA4_min = wuReadData::ReadValue<double>("BETA4_min",inputcardfilename);
  double BETA4_max = wuReadData::ReadValue<double>("BETA4_max",inputcardfilename);
  double GAMM_bin = wuReadData::ReadValue<double>("GAMM_bin",inputcardfilename);
  double GAMM_min = wuReadData::ReadValue<double>("GAMM_min",inputcardfilename);
  double GAMM_max = wuReadData::ReadValue<double>("GAMM_max",inputcardfilename);
  int IZ = wuReadData::ReadValue<int>("IZ",inputcardfilename);
  int IN = wuReadData::ReadValue<int>("IN",inputcardfilename);

  // 以下参数为输入卡jxgamma_N.inp
  char jxgammaNfilename[128]="jxgamma_N.inp";
  int N_PHYSIN_IVAR = wuReadData::ReadValue<int>("N_PHYSIN_IVAR",inputcardfilename);
  int N_ISETS = wuReadData::ReadValue<int>("N_ISETS",inputcardfilename);
  int N_NCUTDN = wuReadData::ReadValue<int>("N_NCUTDN",inputcardfilename);
  int N_NCUTGN = wuReadData::ReadValue<int>("N_NCUTGN",inputcardfilename);
  int N_NNND = wuReadData::ReadValue<int>("N_NNND",inputcardfilename);
  int N_AUXILI_IDECOM = wuReadData::ReadValue<int>("N_AUXILI_IDECOM",inputcardfilename);

  // 以下参数为输入卡jxgamma_P.inp
  char jxgammaPfilename[128]="jxgamma_P.inp";
  int P_PHYSIN_IVAR = wuReadData::ReadValue<int>("P_PHYSIN_IVAR",inputcardfilename);
  int P_ISETS = wuReadData::ReadValue<int>("P_ISETS",inputcardfilename);
  int P_NCUTDP = wuReadData::ReadValue<int>("P_NCUTDP",inputcardfilename);
  int P_NCUTGP = wuReadData::ReadValue<int>("P_NCUTGP",inputcardfilename);
  int P_NNND = wuReadData::ReadValue<int>("P_NNND",inputcardfilename);
  int P_AUXILI_IDECOM = wuReadData::ReadValue<int>("P_AUXILI_IDECOM",inputcardfilename);

  // 以下参数为输入卡 hfbc_N.inp
  char hfbcNfilename[128]="hfbc_N.inp";
  int N_DEFINE_IPROJ = wuReadData::ReadValue<int>("N_DEFINE_IPROJ",inputcardfilename);
  int N_IPRINT = wuReadData::ReadValue<int>("N_IPRINT",inputcardfilename);
  int N_IPLOT = wuReadData::ReadValue<int>("N_IPLOT",inputcardfilename);
  int N_IMODEL = wuReadData::ReadValue<int>("N_IMODEL",inputcardfilename);
  double N_STARTI_OMEGIN = wuReadData::ReadValue<double>("N_STARTI_OMEGIN",inputcardfilename);
  double N_STEPOM = wuReadData::ReadValue<double>("N_STEPOM",inputcardfilename);
  int N_ILOM = wuReadData::ReadValue<int>("N_ILOM",inputcardfilename);
  double N_DELG = wuReadData::ReadValue<double>("N_DELG",inputcardfilename);
  double N_STD = wuReadData::ReadValue<double>("N_STD",inputcardfilename);
  double N_OMCRIT = wuReadData::ReadValue<double>("N_OMCRIT",inputcardfilename);
  double N_DELTA0 = wuReadData::ReadValue<double>("N_DELTA0",inputcardfilename);
  double N_YLAMM = wuReadData::ReadValue<double>("N_YLAMM",inputcardfilename);
  int N_NQPPPS_1 = wuReadData::ReadValue<int>("N_NQPPPS_1",inputcardfilename);
  int N_NQPPNS_1 = wuReadData::ReadValue<int>("N_NQPPNS_1",inputcardfilename);
  int N_NQNPPS_1 = wuReadData::ReadValue<int>("N_NQNPPS_1",inputcardfilename);
  int N_NQNPNS_1 = wuReadData::ReadValue<int>("N_NQNPNS_1",inputcardfilename);
  int N_NQPPPS_2 = wuReadData::ReadValue<int>("N_NQPPPS_2",inputcardfilename);
  int N_NQPPNS_2 = wuReadData::ReadValue<int>("N_NQPPNS_2",inputcardfilename);
  int N_NQNPPS_2 = wuReadData::ReadValue<int>("N_NQNPPS_2",inputcardfilename);
  int N_NQNPNS_2 = wuReadData::ReadValue<int>("N_NQNPNS_2",inputcardfilename);
  int N_NQPPPS_3 = wuReadData::ReadValue<int>("N_NQPPPS_3",inputcardfilename);
  int N_NQPPNS_3 = wuReadData::ReadValue<int>("N_NQPPNS_3",inputcardfilename);
  int N_NQNPPS_3 = wuReadData::ReadValue<int>("N_NQNPPS_3",inputcardfilename);
  int N_NQNPNS_3 = wuReadData::ReadValue<int>("N_NQNPNS_3",inputcardfilename);

  // 以下参数为输入卡 hfbc_P.inp
  char hfbcPfilename[128]="hfbc_P.inp";
  int P_DEFINE_IPROJ = wuReadData::ReadValue<int>("P_DEFINE_IPROJ",inputcardfilename);
  int P_IPRINT = wuReadData::ReadValue<int>("P_IPRINT",inputcardfilename);
  int P_IPLOT = wuReadData::ReadValue<int>("P_IPLOT",inputcardfilename);
  int P_IMODEL = wuReadData::ReadValue<int>("P_IMODEL",inputcardfilename);
  double P_STARTI_OMEGIN = wuReadData::ReadValue<double>("P_STARTI_OMEGIN",inputcardfilename);
  double P_STEPOM = wuReadData::ReadValue<double>("P_STEPOM",inputcardfilename);
  int P_ILOM = wuReadData::ReadValue<int>("P_ILOM",inputcardfilename);
  double P_DELG = wuReadData::ReadValue<double>("P_DELG",inputcardfilename);
  double P_STD = wuReadData::ReadValue<double>("P_STD",inputcardfilename);
  double P_OMCRIT = wuReadData::ReadValue<double>("P_OMCRIT",inputcardfilename);
  double P_DELTA0 = wuReadData::ReadValue<double>("P_DELTA0",inputcardfilename);
  double P_YLAMM = wuReadData::ReadValue<double>("P_YLAMM",inputcardfilename);
  int P_NQPPPS_1 = wuReadData::ReadValue<int>("P_NQPPPS_1",inputcardfilename);
  int P_NQPPNS_1 = wuReadData::ReadValue<int>("P_NQPPNS_1",inputcardfilename);
  int P_NQNPPS_1 = wuReadData::ReadValue<int>("P_NQNPPS_1",inputcardfilename);
  int P_NQNPNS_1 = wuReadData::ReadValue<int>("P_NQNPNS_1",inputcardfilename);
  int P_NQPPPS_2 = wuReadData::ReadValue<int>("P_NQPPPS_2",inputcardfilename);
  int P_NQPPNS_2 = wuReadData::ReadValue<int>("P_NQPPNS_2",inputcardfilename);
  int P_NQNPPS_2 = wuReadData::ReadValue<int>("P_NQNPPS_2",inputcardfilename);
  int P_NQNPNS_2 = wuReadData::ReadValue<int>("P_NQNPNS_2",inputcardfilename);
  int P_NQPPPS_3 = wuReadData::ReadValue<int>("P_NQPPPS_3",inputcardfilename);
  int P_NQPPNS_3 = wuReadData::ReadValue<int>("P_NQPPNS_3",inputcardfilename);
  int P_NQNPPS_3 = wuReadData::ReadValue<int>("P_NQNPPS_3",inputcardfilename);
  int P_NQNPNS_3 = wuReadData::ReadValue<int>("P_NQNPNS_3",inputcardfilename);

  // 以下参数为输入卡 spag2psk.inp
  char spag2pskfilename[128]="spag2psk.inp";
  int INDAT = wuReadData::ReadValue<int>("INDAT",inputcardfilename);
  double YMIN = wuReadData::ReadValue<double>("YMIN",inputcardfilename);
  double YMAX = wuReadData::ReadValue<double>("YMAX",inputcardfilename);
  double YSTEP = wuReadData::ReadValue<double>("YSTEP",inputcardfilename);

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  
  char outputfilename[128];
  char tempchar[128];

  system("if exist *.inp del *.inp");
  system("if exist *.out del *.out");

  sprintf(tempchar,"if exist %s rd/s/q %s",outputdir.c_str(),outputdir.c_str());
  cout<<tempchar<<endl;
  system(tempchar);

  sprintf(tempchar,"md %s",outputdir.c_str());
  system(tempchar);

  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  std::ofstream write;
  
  write.open(jxgammaNfilename);
  if(write.fail()) cout<<"Can't open file: "<<jxgammaNfilename<<endl;
  write<<" &PHYSIN IVAR="<<N_PHYSIN_IVAR<<","<<endl;
  write<<" ISETS="<<N_ISETS <<","<<endl;
  write<<" NCUTDN="<<N_NCUTDN <<","<<endl;
  write<<" NCUTGN="<<N_NCUTGN <<","<<endl;
  write<<" NNND="<<N_NNND <<" &"<<endl;
  write<<" &AUXILI IDECOM="<<N_AUXILI_IDECOM <<" &"<<endl;
  write<<"NEUTRONS"<<endl;
  write.close();
  sprintf(tempchar,"copy %s %s",jxgammaNfilename,outputdir.c_str());
  system(tempchar);

  write.open(jxgammaPfilename);
  if(write.fail()) cout<<"Can't open file: "<<jxgammaPfilename<<endl;
  write<<" &PHYSIN IVAR="<<P_PHYSIN_IVAR<<","<<endl;
  write<<" ISETS="<<P_ISETS <<","<<endl;
  write<<" NCUTDP="<<P_NCUTDP <<","<<endl;
  write<<" NCUTGP="<<P_NCUTGP <<","<<endl;
  write<<" NNND="<<P_NNND <<" &"<<endl;
  write<<" &AUXILI IDECOM="<<P_AUXILI_IDECOM <<" &"<<endl;
  write<<"PROTONS"<<endl;
  write.close();
  sprintf(tempchar,"copy %s %s",jxgammaPfilename,outputdir.c_str());
  system(tempchar);

  write.open(hfbcNfilename);
  if(write.fail()) cout<<"Can't open file: "<<hfbcNfilename<<endl;
  write<<" &DEFINE IPROJ="<<N_DEFINE_IPROJ<<", IPRINT="<<N_IPRINT<<", IPLOT="<<N_IPLOT<<", IMODEL="<<N_IMODEL<<" &"<<endl;
  write<<" &STARTI OMEGIN="<<N_STARTI_OMEGIN<<","<<endl;
  write<<" STEPOM="<<N_STEPOM<<","<<endl;
  write<<" ILOM="<<N_ILOM<<","<<endl;
  write<<" DELG="<<N_DELG<<","<<endl;
  write<<" STD="<<N_STD<<","<<endl;
  write<<"  OMCRIT="<<N_OMCRIT<<","<<endl;
  write<<"  DELTA0="<<N_DELTA0<<","<<endl;
  write<<"  YLAMM="<<N_YLAMM<<" &"<<endl;
  write<<" &CONFIG NQPPPS(1)="<<N_NQPPPS_1<<", NQPPPS(2)="<<N_NQPPPS_2<<", NQPPPS(3)="<<N_NQPPPS_3<<","<<endl;
  write<<"         NQPPNS(1)="<<N_NQPPNS_1<<", NQPPNS(2)="<<N_NQPPNS_2<<", NQPPNS(3)="<<N_NQPPNS_3<<","<<endl;
  write<<"         NQNPPS(1)="<<N_NQNPPS_1<<", NQNPPS(2)="<<N_NQNPPS_2<<", NQNPPS(3)="<<N_NQNPPS_3<<","<<endl;
  write<<"         NQNPNS(1)="<<N_NQNPNS_1<<", NQNPNS(2)="<<N_NQNPNS_2<<", NQNPNS(3)="<<N_NQNPNS_3<<"     &"<<endl;
  write<<"NEUTRONS"<<endl;
  write.close();
  sprintf(tempchar,"copy %s %s",hfbcNfilename,outputdir.c_str());
  system(tempchar);

  write.open(hfbcPfilename);
  if(write.fail()) cout<<"Can't open file: "<<hfbcPfilename<<endl;
  write<<" &DEFINE IPROJ="<<P_DEFINE_IPROJ<<", IPRINT="<<P_IPRINT<<", IPLOT="<<P_IPLOT<<", IMODEL="<<P_IMODEL<<" &"<<endl;
  write<<" &STARTI OMEGIN="<<P_STARTI_OMEGIN<<","<<endl;
  write<<" STEPOM="<<P_STEPOM<<","<<endl;
  write<<" ILOM="<<P_ILOM<<","<<endl;
  write<<" DELG="<<P_DELG<<","<<endl;
  write<<" STD="<<P_STD<<","<<endl;
  write<<"  OMCRIT="<<P_OMCRIT<<","<<endl;
  write<<"  DELTA0="<<P_DELTA0<<","<<endl;
  write<<"  YLAMM="<<P_YLAMM<<" &"<<endl;
  write<<" &CONFIG NQPPPS(1)="<<P_NQPPPS_1<<", NQPPPS(2)="<<P_NQPPPS_2<<", NQPPPS(3)="<<P_NQPPPS_3<<","<<endl;
  write<<"         NQPPNS(1)="<<P_NQPPNS_1<<", NQPPNS(2)="<<P_NQPPNS_2<<", NQPPNS(3)="<<P_NQPPNS_3<<","<<endl;
  write<<"         NQNPPS(1)="<<P_NQNPPS_1<<", NQNPPS(2)="<<P_NQNPPS_2<<", NQNPPS(3)="<<P_NQNPPS_3<<","<<endl;
  write<<"         NQNPNS(1)="<<P_NQNPNS_1<<", NQNPNS(2)="<<P_NQNPNS_2<<", NQNPNS(3)="<<P_NQNPNS_3<<"     &"<<endl;
  write<<"PROTONS"<<endl;
  write.close();
  sprintf(tempchar,"copy %s %s",hfbcPfilename,outputdir.c_str());
  system(tempchar);

  write.open(spag2pskfilename);
  if(write.fail()) cout<<"Can't open file: "<<spag2pskfilename<<endl;
  write<<" &INPUT INDAT="<<INDAT<<","<<endl;
  write<<"        YMIN="<<YMIN<<","<<endl;
  write<<"        YMAX="<<YMAX<<","<<endl;
  write<<"        YSTEP="<<YSTEP<<" &"<<endl;
  write<<"NEUTRONS"<<endl;
  write.close();
  sprintf(tempchar,"copy %s %s",spag2pskfilename,outputdir.c_str());
  system(tempchar);

  sprintf(tempchar,"copy %s %s",inputcardfilename.c_str(),outputdir.c_str());
  system(tempchar);
  
  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  
  for(double i=BETA2_min;i<=BETA2_max;i+=BETA2_bin)
    for(double j=BETA4_min;j<=BETA4_max;j+=BETA4_bin)
      for(double k=GAMM_min;k<=GAMM_max;k+=GAMM_bin)
	{
	  sprintf(outputfilename,"%s\\%f_%f_%f",outputdir.c_str(),i,j,k);
	  cout<<outputfilename<<endl;

	  sprintf(tempchar,"md %s",outputfilename);
	  system(tempchar);

	  write.open(swgammafilename);
	  if(write.fail()) cout<<"Can't open file: "<<swgammafilename<<endl;
	  write<<" &INTDAT IAUTO="<<INTDAT_IAUTO<<", NAZWIS="<<NAZWIS<<" &"<<endl;
	  write<<" &DYNAMC BETA2="<<i<<", BETA4="<<j<<", GAMM="<<k<<", IZ="<<IZ<<", IN="<<IN<<" &"<<endl;
	  write<<"DONE"<<endl;
	  write.close();

	  system("loop.bat");


	  sprintf(tempchar,"copy %s %s",swgammafilename,outputfilename);
	  system(tempchar);


	  sprintf(tempchar,"copy %s %s","swgamma.out",outputfilename);
	  system(tempchar);

	  sprintf(tempchar,"copy %s %s","jxgamma_N.out",outputfilename);
	  system(tempchar);
	  sprintf(tempchar,"copy %s %s","jxgamma_P.out",outputfilename);
	  system(tempchar);

	  sprintf(tempchar,"copy %s %s","input_N.psk",outputfilename);
	  system(tempchar);
	  sprintf(tempchar,"copy %s %s","input_P.psk",outputfilename);
	  system(tempchar);

	  sprintf(tempchar,"copy %s %s","output_N.ps",outputfilename);
	  system(tempchar);
	  sprintf(tempchar,"copy %s %s","output_P.ps",outputfilename);
	  system(tempchar);

	}


  system("clean.bat");

  return 0;
}


// 
// AutomaticRun.cc ends here
