void plotaGC()
{
  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("aGC.C++");
  setTDRStyle();  
  version=0; // version=1 --> simplified plot
  TString str("aGC_v"); str+=version;
  aGC()->Print(str+".pdf");
  aGC()->Print(str+".png");
  return;
}

