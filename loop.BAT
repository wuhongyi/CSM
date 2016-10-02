
echo '== @@@@@@@@@@@@@@@@@@@@@@@@ =='


swgamma>swgamma.out

move jxgamma_N.inp jxgamma.inp
jxgamma>jxgamma_N.out
del fort.11
move fort.12 fort_N.11
move jxgamma.inp jxgamma_N.inp

move jxgamma_P.inp jxgamma.inp
jxgamma>jxgamma_P.out
del fort.11
move fort.12 fort_P.11
move jxgamma.inp jxgamma_P.inp

move  fort_N.11 fort.11
move  hfbc_N.inp hfbc.inp
hfbc>hfbc_N.out
del fort.9
spag2psk
move fort.9 output.psk
del fort.*
move output.psk input.psk
pskc
move output.ps output_N.ps
move input.psk input_N.psk
move hfbc.inp hfbc_N.inp

move  fort_P.11 fort.11
move  hfbc_P.inp hfbc.inp
hfbc>hfbc_P.out
del fort.9
spag2psk
move fort.9 output.psk
del fort.*
move output.psk input.psk
pskc
move output.ps output_P.ps
move input.psk input_P.psk
move hfbc.inp hfbc_P.inp