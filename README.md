aTGC Summary Plot
=================

```
These scripts produce the aTGC limits comparison plots.

Running Instructions
====================

cd ~/private/aTGC/CMSSW_8_0_28/src/aTGCsAnalysis/
cmsenv
cd -
root -l plotaGC.C
# This does not work in ROOT 6. Loading macros in scripts does not work. So instead open ROOT and copy commands from plotaGC.txt i.e.

gROOT->LoadMacro("tdrstyle.C");
gROOT->LoadMacro("aGC.C++");
setTDRStyle();
version=0; // version=1 --> simplified plot
TString str("aGC_v"); str+=version;
aGC()->Print(str+".pdf");
aGC()->Print(str+".png");

