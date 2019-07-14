

enum {  k_atlas_ww_dkz, k_atlas_ww8_dkz, k_cms_ww8_dkz, k_atlas_wz_dkz, k_atlas_wz8_dkz, k_atlas_wz13_dkz, k_atlas_wz813_dkz, k_cms_wz8_dkz, k_cms_wz13_dkz, k_atlas_wv_dkz, k_cms_wv_dkz, k_cms_wv8_dkz, k_cms_wv13_dkz, k_atlas_vbfw8_dkz, k_cms_vbfwvbfz13_dkz, k_lep_ww_dkz, k_atlas_ww_dk,  k_d0_vv_dk, k_cms_wv13_2016_dkz,

k_atlas_ww_lz, k_atlas_ww8_lz, k_atlas_ww13_lz, k_cms_ww_lz, k_cms_ww8_lz,  k_atlas_wz_lz, k_atlas_wz8_lz, k_atlas_wz13_lz, k_atlas_wz813_lz, k_cms_wz8_lz, k_cms_wz13_lz, k_atlas_wv_lz,  k_atlas_wvjj8_lz, k_atlas_wvJ8_lz, k_cms_wv_lz, k_cms_wv8_lz, k_cms_wv13_lz, k_atlas_vbfw8_lz, k_atlas_vbfz8_lz, k_cms_vbfwvbfz13_lz, k_d0_vv_lz,  k_lep_ww_lz, k_cms_wv13_2016_lz,

k_atlas_ww_dgz, k_atlas_ww8_dgz, k_atlas_ww13_dgz, k_cms_ww_dgz,  k_cms_ww8_dgz,  k_atlas_wz_dgz, k_atlas_wz8_dgz, k_atlas_wz13_dgz, k_atlas_wz813_dgz, k_cms_wz8_dgz, k_cms_wz13_dgz, k_atlas_wv_dgz,  k_atlas_wvjj8_dgz, k_atlas_wvJ8_dgz, k_cms_wv8_dgz, k_cms_wv13_dgz, k_atlas_vbfw8_dgz, k_cms_vbfwvbfz13_dgz, k_d0_vv_dgz, k_lep_ww_dgz, k_cms_wv13_2016_dgz,

k_nChan };

// Available plot sets
bool catgcg = false;
bool catgcz = true;
bool natgcg = false;
bool natgcz = false;

bool atgc = catgcg||catgcz||natgcg||natgcz;

bool aqgc_a = false;
bool aqgc_ft = false; 
bool aqgc_fm = false;
bool aqgc_fs = false;

bool aqgc = aqgc_a||aqgc_fs||aqgc_fm||aqgc_ft;

bool lineStyles = false;

bool aqgc_wg8 = false;
bool aqgc_zg8 = false;
bool aqgc_zz13 = false;

float scale_h3 = 100;
float scale_h4 = 10000;


// tan2thetaw = sin2thetaW/cos2thetaw = sin2thetaw/(M_W^2/M_Z^2) = 0.23126/((0.080385*0.080385)/(0.0911876*0.0911876))
float tan2thetaw =  0.23126/((0.080385*0.080385)/(0.0911876*0.0911876)); 


// ac0 = - fm0 * 4.0 * m_W^2 / g^2 -  fm2 * 8.0 * m_W^2 / g'^2
// note reverse positive and negative values
// where fm2 = 1/2 * fm0
// and g = e/ sin(theta_W),  g = sqrt(0.00781616*4.0*3.14159)/sin(theta_W)
// and g' = e/cos(theta_W), g' = sqrt(0.00781616*4.0*3.14169)/(m_W/m_Z)

// ac0 = fm0*(4.0 * 0.080385 * 0.080385 * (0.23126 /(0.00781616*4.0*3.14159)) + 4.0 * 0.080385 * 0.080385 * ((0.080385 * 0.080385/(0.0911876*0.0911876)) /(0.00781616*4.0*3.14159)))

float fm0toa0w = (4.0 * 0.080385 * 0.080385 * (0.23126 /(0.00781616*4.0*3.14159)) + 4.0 * 0.080385 * 0.080385 * ((0.080385 * 0.080385/(0.0911876*0.0911876)) /(0.00781616*4.0*3.14159)));

float g = sqrt(0.00781616*4.0*3.14159)/sqrt(0.23126);
float gp = sqrt(0.00781616*4.0*3.14169)/(0.080385/0.0911876);
float mw = 0.080385;
float mz = 0.0911876;

  // ac1 = fm1 * 4.0 * m_W^2 / g^2 + fm1 * 8.0 * m_W^2 / g'^2

  float fm1toacw = fm0toa0w;

// ATLAS gg->WW
// a0W = g^2*v^2*fm0 =
//     = 4^M_W^2*fm0

// CMS gg->WW
// a0W = (4*M_W^2/e^2)*fm0 = (4*M_W^2/(g*sin(theta_W))^2)*

// Thus fm0_cms = (g*sin(theta_W))^2)*fm0_ATLAS

// rather than g^2 as in the VBFNLO to MG5 conversion

// as opposed to CMS WVg
// a0W = (4*M_W^2/g^2)*fm0 + (8*M_W^2/g'^2)*fm2
//     = (4*M_W^2)*fm0_vbfnlo + (2*M_W^2)*fm2_VBFNLO
//     = (4*M_W^2)*fm0_vbfnlo + (4*M_W)*fm0_VBFNLO
//     = (8*M_W^2)*fm0_vbfnlo
// which differs by g^2 as in the VBFNLO to MG5 conversion but with a factor of two


// a to madgraph f for f0 f1 ATLAS
// a = (g^2*v^2)*f_vbfnlo
// a = (4*mW^2)*f_vbfnlo
// a = (4*mW^2)*(1/g^2)*f_madgraph


// This should be for ATLAS results
float madftoa = 4.0*mw*mw/(g*g);


int nPlotChan = 0;
vector<bool> plotChan( k_nChan, false );
vector<string> 
chanName(        k_nChan ),
  chanMeasurement( k_nChan ),
  chanResult (     k_nChan ),
  chanLumi   (     k_nChan ),
  chanSqrtS  (     k_nChan ),
  chanExp    (     k_nChan );
vector<int>
chanColor( k_nChan),
  chanLine(k_nChan);
vector<float> 
  chanaCC( k_nChan,0 ), 
  chanaCP( k_nChan,0 ),
  chanaCM( k_nChan,0 );

 float scale_;
 int chan;

scale_ = (1);


if (catgcz)
  {

// SMP-18-008

  chanName[k_cms_wv13_2016_dkz]            = "#Delta#kappa_{Z}";
  chanMeasurement[k_cms_wv13_2016_dkz]     = "WV (l#nuJ)";
  chanLumi[k_cms_wv13_2016_dkz]            = "35.9 ";
  chanSqrtS[k_cms_wv13_2016_dkz]          = "13 ";
  chanExp[k_cms_wv13_2016_dkz]            = "CMS";
  chanaCC[k_cms_wv13_2016_dkz]  = 0.0   * scale_;
  chanaCM[k_cms_wv13_2016_dkz]  = -0.0079 * scale_;
  chanaCP[k_cms_wv13_2016_dkz]  = +0.0082 * scale_;
  plotChan[k_cms_wv13_2016_dkz] = true;

  chanName[k_cms_wv13_2016_lz]            = "#lambda_{Z}";
  chanMeasurement[k_cms_wv13_2016_lz]     = "WV (l#nuJ)";
  chanLumi[k_cms_wv13_2016_lz]            = "35.9 ";
  chanSqrtS[k_cms_wv13_2016_lz]          = "13 ";
  chanExp[k_cms_wv13_2016_lz]            = "CMS";
  chanaCC[k_cms_wv13_2016_lz]  = 0.0   * scale_;
  chanaCM[k_cms_wv13_2016_lz]  = -0.0065 * scale_;
  chanaCP[k_cms_wv13_2016_lz]  = +0.0066 * scale_;
  plotChan[k_cms_wv13_2016_lz] = true;

  chanName[k_cms_wv13_2016_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_cms_wv13_2016_dgz]     = "WV (l#nuJ)";
  chanLumi[k_cms_wv13_2016_dgz]            = "35.9 ";
  chanSqrtS[k_cms_wv13_2016_dgz]          = "13 ";
  chanExp[k_cms_wv13_2016_dgz]            = "CMS";
  chanaCC[k_cms_wv13_2016_dgz]  = 0.0   * scale_;
  chanaCM[k_cms_wv13_2016_dgz]  = -0.0061 * scale_;
  chanaCP[k_cms_wv13_2016_dgz]  = +0.0074 * scale_;
  plotChan[k_cms_wv13_2016_dgz] = true;

// ATLAS http://arxiv.org/abs/1210.2979 submitted to Phys. Rev. D

  // http://arxiv.org/abs/1603.01702, https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/STDM-2013-07/#auxstuff

  chan = k_atlas_ww8_dkz;
  chanName[chan]            = "#Delta#kappa_{Z}";
  chanMeasurement[chan]     = "WW";
  chanLumi[chan]            = "20.3 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "8 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.025 * scale_; 
  chanaCP[chan]  =  0.020 * scale_;  
  plotChan[chan] = true; 


  chanName[k_atlas_ww_dkz]            = "#Delta#kappa_{Z}";
  chanMeasurement[k_atlas_ww_dkz]     = "WW";
  chanLumi[k_atlas_ww_dkz]            = "4.6 ";
  chanSqrtS[k_atlas_ww_dkz]          = "7 ";
  chanExp[k_atlas_ww_dkz]            = "ATLAS";
  chanaCC[k_atlas_ww_dkz]  = 0.0   * scale_; 
  chanaCM[k_atlas_ww_dkz]  = -0.043 * scale_; 
  chanaCP[k_atlas_ww_dkz]  = +0.043 * scale_; 
  plotChan[k_atlas_ww_dkz] = true;


  // // http://arxiv.org/abs/1507.03268

  chanName[k_cms_ww8_dkz]            = "#Delta#kappa_{Z}";
  chanMeasurement[k_cms_ww8_dkz]     = "WW";
  chanLumi[k_cms_ww8_dkz]            = "19.4 ";
  chanSqrtS[k_cms_ww8_dkz]          = "8 ";
  chanExp[k_cms_ww8_dkz]            = "CMS";
  chanaCC[k_cms_ww8_dkz]  =     (-3.6 + 3.2*0.30082992949) * 0.5 * 0.080385 * 0.080385 * scale_; 
  chanaCM[k_cms_ww8_dkz]  = (-11.4 - 23.9*0.30082992949) * 0.5 * 0.080385 * 0.080385 * scale_; 
  chanaCP[k_cms_ww8_dkz]  = (5.4 + 29.2*0.30082992949) * 0.5 * 0.080385 * 0.080385 * scale_; 
  plotChan[k_cms_ww8_dkz] = true; 

   // https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/STDM-2014-02/, http://arxiv.org/abs/1603.02151

  chan = k_atlas_wz8_dkz;
  chanName[chan]            = "#Delta#kappa_{Z}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "20.3 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "8 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  =  -0.19 * scale_; 
  chanaCP[chan]  =  0.30 * scale_;  
  plotChan[chan] = false; 


 //https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/CONFNOTES/ATLAS-CONF-2016-043/
  chan = k_atlas_wz13_dkz;
  chanName[chan]            = "#Delta#kappa_{Z}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "13.3 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "13 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  =  -0.15 * scale_; 
  chanaCP[chan]  =  0.26 * scale_;  
  plotChan[chan] = false; 


  chan = k_atlas_wz813_dkz;
  chanName[chan]            = "#Delta#kappa_{Z}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "33.6 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "8,13 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  =  -0.13 * scale_; 
  chanaCP[chan]  =  0.24 * scale_;  
  plotChan[chan] = true; 

  
  
  // ATALS http://arxiv.org/abs/1208.1390 Eur.Phys.J. C72 (2012) 2173
  // Not competative

   chanName[k_atlas_wz_dkz]            = "#Delta#kappa_{Z}";
   chanMeasurement[k_atlas_wz_dkz]     = "WZ";
   chanLumi[k_atlas_wz_dkz]            = "4.6 ";
   chanExp[k_atlas_wz_dkz]            = "ATLAS";
   chanaCC[k_atlas_wz_dkz]  = 0.0   * scale_; 
   chanaCM[k_atlas_wz_dkz]  = -0.37 * scale_; 
   chanaCP[k_atlas_wz_dkz]  = +0.57 * scale_; 
   plotChan[k_atlas_wz_dkz] = false;


// Atlas http://arxiv.org/abs/1410.7238 submitted to JHEP

  chanName[k_atlas_wv_dkz]            = "#Delta#kappa_{Z}";
  chanMeasurement[k_atlas_wv_dkz]     = "WV (l#nujj)";
  chanLumi[k_atlas_wv_dkz]            = "4.6 ";
  chanSqrtS[k_atlas_wv_dkz]          = "7 ";
  chanExp[k_atlas_wv_dkz]            = "ATLAS";
  chanaCC[k_atlas_wv_dkz]  = 0.0   * scale_; 
  chanaCM[k_atlas_wv_dkz]  = -0.090 * scale_; 
  chanaCP[k_atlas_wv_dkz]  = +0.105 * scale_; 
  plotChan[k_atlas_wv_dkz] = true;


// CMS http://arxiv.org/abs/1210.7544 Sub to Eur. Phys. J. C

  chanName[k_cms_wv_dkz]            = "#Delta#kappa_{Z}";
  chanMeasurement[k_cms_wv_dkz]     = "WV (l#nujj)";
  chanLumi[k_cms_wv_dkz]            = "5.0 ";
  chanSqrtS[k_cms_wv_dkz]          = "7 ";
  chanExp[k_cms_wv_dkz]            = "CMS";
  chanaCC[k_cms_wv_dkz]  = 0.0   * scale_; 
  chanaCM[k_cms_wv_dkz]  = -0.043 * scale_; 
  chanaCP[k_cms_wv_dkz]  = +0.033 * scale_; 
  plotChan[k_cms_wv_dkz] = true;

// LEP  hep-ex/0212036 and hep-ex/0307056, http://arxiv.org/abs/1302.3415

  chanName[k_lep_ww_dkz]            = "#Delta#kappa_{Z}";
  chanMeasurement[k_lep_ww_dkz]     = "LEP comb.";
  chanLumi[k_lep_ww_dkz]            = "0.7 ";
  chanSqrtS[k_lep_ww_dkz]          = "0.20 ";
 chanExp[k_lep_ww_dkz]            = "LEP";
  chanaCC[k_lep_ww_dkz]  = -0.011   * scale_; 
  chanaCM[k_lep_ww_dkz]  = -0.074 * scale_; 
  chanaCP[k_lep_ww_dkz]  = +0.051 * scale_; 
  plotChan[k_lep_ww_dkz] = true;

// ATLAS http://arxiv.org/abs/1210.2979 submitted to Phys. Rev. D

//   chanName[k_atlas_ww_dk]            = "#Delta#kappa_{Z}";
//   chanMeasurement[k_atlas_ww_dk]     = "WW (EC #Delta#kappa)";
//   chanLumi[k_atlas_ww_dk]            = "4.6 ";
//   chanExp[k_atlas_ww_dk]            = "ATLAS";
//   chanaCC[k_atlas_ww_dk]  = 0.0   * scale_; 
//   chanaCM[k_atlas_ww_dk]  = -0.061 * scale_; 
//   chanaCP[k_atlas_ww_dk]  = +0.083 * scale_; 
//   plotChan[k_atlas_ww_dk] = true;





  // ATALS CDF WZ not competative, CDF WW not competative


// D0 http://arxiv.org/abs/1208.5458 Phys.Lett. B718 (2012) 451-459

//   chanName[k_d0_vv_dk]            = "#Delta#kappa_{Z}";
//   chanMeasurement[k_d0_vv_dk]     = "D0 comb.(EC #Delta#kappa)";
//   chanLumi[k_d0_vv_dk]            = "8.6 ";
//   chanExp[k_d0_vv_dk]            = "D0";
//   chanaCC[k_d0_vv_dk]  = 0.037   * scale_; 
//   chanaCM[k_d0_vv_dk]  = -0.049 * scale_; 
//   chanaCP[k_d0_vv_dk]  = +0.124 * scale_; 
//   plotChan[k_d0_vv_dk] = true;



 // http://arxiv.org/abs/1603.01702, https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/STDM-2013-07/#auxstuff

  chan = k_atlas_ww8_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "WW";
  chanLumi[chan]            = "20.3 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "8 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.019 * scale_; 
  chanaCP[chan]  =  0.019 * scale_;  
  plotChan[chan] = true; 


// ATLAS http://arxiv.org/abs/1210.2979 submitted to Phys. Rev. D

 chanName[k_atlas_ww_lz]            = "#lambda_{Z}";
  chanMeasurement[k_atlas_ww_lz]     = "WW";
  chanLumi[k_atlas_ww_lz]            = "4.6 ";
  chanSqrtS[k_atlas_ww_lz]          = "7 ";
  chanExp[k_atlas_ww_lz]            = "ATLAS";
  chanaCC[k_atlas_ww_lz]  = 0.0   * scale_; 
  chanaCM[k_atlas_ww_lz]  = -0.062 * scale_; 
  chanaCP[k_atlas_ww_lz]  = +0.059 * scale_; 
  plotChan[k_atlas_ww_lz] = true;


  // CMS https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP12005

 chanName[k_cms_ww_lz]            = "#lambda_{Z}";
  chanMeasurement[k_cms_ww_lz]     = "WW";
  chanLumi[k_cms_ww_lz]            = "4.9 ";
  chanSqrtS[k_cms_ww_lz]          = "7 ";
  chanExp[k_cms_ww_lz]            = "CMS";
  chanaCC[k_cms_ww_lz]  = 0.0   * scale_; 
  chanaCM[k_cms_ww_lz]  = -0.048 * scale_; 
  chanaCP[k_cms_ww_lz]  = +0.048 * scale_; 
  plotChan[k_cms_ww_lz] = true;

  // http://arxiv.org/abs/1507.03268

 chanName[k_cms_ww8_lz]            = "#lambda_{Z}";
  chanMeasurement[k_cms_ww8_lz]     = "WW";
  chanLumi[k_cms_ww8_lz]            = "19.4 ";
  chanSqrtS[k_cms_ww8_lz]          = "8 ";
  chanExp[k_cms_ww8_lz]            = "CMS";
  chanaCC[k_cms_ww8_lz]  = 0.1 * 1.5 * (8 * 0.70710678118 * 1.16637e-5 * 80.385 * 80.385) *  0.080385 * 0.080385  * scale_; 
  chanaCM[k_cms_ww8_lz]  = -5.7 * 1.5 * (8 * 0.70710678118 * 1.16637e-5 * 80.385 * 80.385) *  0.080385 * 0.080385 * scale_; 
  chanaCP[k_cms_ww8_lz]  = 5.9 * 1.5 * (8 * 0.70710678118 * 1.16637e-5 * 80.385 * 80.385) *  0.080385 * 0.080385 * scale_; 
  plotChan[k_cms_ww8_lz] = true;


 // https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/STDM-2014-02/, http://arxiv.org/abs/1603.02151

  chan = k_atlas_wz8_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "20.3 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "8 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  =  -0.016 * scale_; 
  chanaCP[chan]  =  0.016 * scale_;  
  plotChan[chan] = false; 


  // ATALS http://arxiv.org/abs/1208.1390 Eur.Phys.J. C72 (2012) 2173

 chanName[k_atlas_wz_lz]            = "#lambda_{Z}";
  chanMeasurement[k_atlas_wz_lz]     = "WZ";
  chanLumi[k_atlas_wz_lz]            = "4.6 ";
  chanSqrtS[k_atlas_wz_lz]          = "7 ";
  chanExp[k_atlas_wz_lz]            = "ATLAS";
  chanaCC[k_atlas_wz_lz]  = 0.0   * scale_; 
  chanaCM[k_atlas_wz_lz]  = -0.046 * scale_; 
  chanaCP[k_atlas_wz_lz]  = +0.047 * scale_; 
  plotChan[k_atlas_wz_lz] = true;

//https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/CONFNOTES/ATLAS-CONF-2016-043/
  chan = k_atlas_wz13_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "13.3 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "13 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  =  -0.016 * scale_; 
  chanaCP[chan]  =  0.015 * scale_;  
  plotChan[chan] = false; 


  chan = k_atlas_wz813_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "33.6 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "8,13 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  =  -0.014 * scale_; 
  chanaCP[chan]  =  0.013 * scale_;  
  plotChan[chan] = true; 

  
  // CDF  http://arxiv.org/abs/0912.4500 Phys.Rev.Lett. 104 (2010) 201801
 // CDF WZ better than WW

//  chanName[k_cdf_ww_lz]            = "#lambda_{Z}";
//   chanMeasurement[k_cdf_ww_lz]     = "WW";
//   chanLumi[k_cdf_ww_lz]            = "3.6 ";
//   chanExp[k_cdf_ww_lz]            = "CDF";
//   chanaCC[k_cdf_ww_lz]  = 0.0   * scale_; 
//   chanaCM[k_cdf_ww_lz]  = -0.14 * scale_; 
//   chanaCP[k_cdf_ww_lz]  = +0.15 * scale_; 
//   plotChan[k_cdf_ww_lz] = true;


  // CDF http://arxiv.org/abs/1202.6629 Phys.Rev. D86 (2012) 031104
  // almost competative

//  chanName[k_cdf_wz_lz]            = "#lambda_{Z}";
//   chanMeasurement[k_cdf_wz_lz]     = "WZ";
//   chanLumi[k_cdf_wz_lz]            = "7.1 ";
//   chanExp[k_cdf_wz_lz]            = "CDF";
//   chanaCC[k_cdf_wz_lz]  = 0.0   * scale_; 
//   chanaCM[k_cdf_wz_lz]  = -0.09 * scale_; 
//   chanaCP[k_cdf_wz_lz]  = +0.11 * scale_; 
//   plotChan[k_cdf_wz_lz] = true;


// Atlas http://arxiv.org/abs/1410.7238 submitted to JHEP


  chanName[k_atlas_wv_lz]            = "#lambda_{Z}";
  chanMeasurement[k_atlas_wv_lz]     = "WV (l#nujj)";
  chanLumi[k_atlas_wv_lz]            = "4.6 ";
  chanSqrtS[k_atlas_wv_lz]          = "7 ";
  chanExp[k_atlas_wv_lz]            = "ATLAS";
  chanaCC[k_atlas_wv_lz]  = 0.0   * scale_; 
  chanaCM[k_atlas_wv_lz]  = -0.039 * scale_; 
  chanaCP[k_atlas_wv_lz]  = +0.040 * scale_; 
  plotChan[k_atlas_wv_lz] = true;



// CMS http://arxiv.org/abs/1210.7544 Sub to Eur. Phys. J. C


  chanName[k_cms_wv_lz]            = "#lambda_{Z}";
  chanMeasurement[k_cms_wv_lz]     = "WV (l#nujj)";
  chanLumi[k_cms_wv_lz]            = "5.0 ";
  chanSqrtS[k_cms_wv_lz]          = "7 ";
  chanExp[k_cms_wv_lz]            = "CMS";
  chanaCC[k_cms_wv_lz]  = 0.0   * scale_; 
  chanaCM[k_cms_wv_lz]  = -0.038 * scale_; 
  chanaCP[k_cms_wv_lz]  = +0.030 * scale_; 
  plotChan[k_cms_wv_lz] = true;



  


// D0 http://arxiv.org/abs/1208.5458 Phys.Lett. B718 (2012) 451-459

  chanName[k_d0_vv_lz]            = "#lambda_{Z}";
  chanMeasurement[k_d0_vv_lz]     = "D0 comb.";
  chanLumi[k_d0_vv_lz]            = "8.6 ";
  chanSqrtS[k_d0_vv_lz]          = "1.96 ";
  chanExp[k_d0_vv_lz]            = "D0";
  chanaCC[k_d0_vv_lz]  = 0.007   * scale_; 
  chanaCM[k_d0_vv_lz]  = -0.036 * scale_; 
  chanaCP[k_d0_vv_lz]  = +0.044 * scale_; 
  plotChan[k_d0_vv_lz] = true;


// LEP  hep-ex/0212036 and hep-ex/0307056,  http://arxiv.org/abs/1302.3415

  chanName[k_lep_ww_lz]            = "#lambda_{Z}";
  chanMeasurement[k_lep_ww_lz]     = "LEP comb.";
  chanLumi[k_lep_ww_lz]            = "0.7 ";
  chanSqrtS[k_lep_ww_lz]          = "0.20 ";
  chanExp[k_lep_ww_lz]            = "LEP";
  chanaCC[k_lep_ww_lz]  = -0.022   * scale_; 
  chanaCM[k_lep_ww_lz]  = -0.059 * scale_; 
  chanaCP[k_lep_ww_lz]  = +0.017 * scale_; 
  plotChan[k_lep_ww_lz] = true;

  // http://arxiv.org/abs/1603.01702, https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/STDM-2013-07/#auxstuff

  chan = k_atlas_ww8_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "WW";
  chanLumi[chan]            = "20.3 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "8 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.016 * scale_; 
  chanaCP[chan]  =  0.027 * scale_;  
  plotChan[chan] = true; 


// ATLAS http://arxiv.org/abs/1210.2979 submitted to Phys. Rev. D

  chanName[k_atlas_ww_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_atlas_ww_dgz]     = "WW";
  chanLumi[k_atlas_ww_dgz]            = "4.6 ";
  chanSqrtS[k_atlas_ww_dgz]          = "7 ";
  chanExp[k_atlas_ww_dgz]            = "ATLAS";
  chanaCC[k_atlas_ww_dgz]  = 0.0   * scale_; 
  chanaCM[k_atlas_ww_dgz]  = -0.039 * scale_; 
  chanaCP[k_atlas_ww_dgz]  = +0.052 * scale_; 
  plotChan[k_atlas_ww_dgz] = true;

  // https://twiki.cern.ch/twiki/bin/view/CMSPublic/PhysicsResultsSMP12005

  chanName[k_cms_ww_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_cms_ww_dgz]     = "WW";
  chanLumi[k_cms_ww_dgz]            = "4.9 ";
  chanSqrtS[k_cms_ww_dgz]          = "7 ";
  chanExp[k_cms_ww_dgz]            = "CMS";
  chanaCC[k_cms_ww_dgz]  = 0.0   * scale_; 
  chanaCM[k_cms_ww_dgz]  = -0.095 * scale_; 
  chanaCP[k_cms_ww_dgz]  = +0.095 * scale_; 
  plotChan[k_cms_ww_dgz] = true;

  // http://arxiv.org/abs/1507.03268

  chanName[k_cms_ww8_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_cms_ww8_dgz]     = "WW";
  chanLumi[k_cms_ww8_dgz]            = "19.4 ";
  chanSqrtS[k_cms_ww8_dgz]          = "8 ";
  chanExp[k_cms_ww8_dgz]            = "CMS";
  chanaCC[k_cms_ww8_dgz]  = -3.6 *  0.5 * 0.0911876 * 0.0911876   * scale_; 
  chanaCM[k_cms_ww8_dgz]  =  -11.4 * 0.5 * 0.0911876 * 0.0911876 * scale_;  
  chanaCP[k_cms_ww8_dgz]  =  +5.4 * 0.5 * 0.0911876 * 0.0911876 * scale_; 
  plotChan[k_cms_ww8_dgz] = true;


  
 // https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/STDM-2014-02/, http://arxiv.org/abs/1603.02151

  chan = k_atlas_wz8_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "20.3 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "8 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  =  -0.019 * scale_; 
  chanaCP[chan]  =  0.029 * scale_;  
  plotChan[chan] = false; 

//https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/CONFNOTES/ATLAS-CONF-2016-043/
  chan = k_atlas_wz13_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "13.3 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "13 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  =  -0.016 * scale_; 
  chanaCP[chan]  =  0.036 * scale_;  
  plotChan[chan] = false; 


  chan = k_atlas_wz813_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "33.6 ";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "8,13 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  =  -0.015 * scale_; 
  chanaCP[chan]  =  0.030 * scale_;  
  plotChan[chan] = true; 



  // ATALS http://arxiv.org/abs/1208.1390 Eur.Phys.J. C72 (2012) 2173

  chanName[k_atlas_wz_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_atlas_wz_dgz]     = "WZ";
  chanLumi[k_atlas_wz_dgz]            = "4.6 ";
  chanSqrtS[k_atlas_wz_dgz]          = "7 ";
  chanExp[k_atlas_wz_dgz]            = "ATLAS";
  chanaCC[k_atlas_wz_dgz]  = 0.0   * scale_; 
  chanaCM[k_atlas_wz_dgz]  =  -0.057 * scale_; 
  chanaCP[k_atlas_wz_dgz]  =  +0.093 * scale_; 
  plotChan[k_atlas_wz_dgz] = true;

// Atlas http://arxiv.org/abs/1410.7238 submitted to JHEP


  chanName[k_atlas_wv_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_atlas_wv_dgz]     = "WV (l#nujj)";
  chanLumi[k_atlas_wv_dgz]            = "4.6 ";
  chanSqrtS[k_atlas_wv_dgz]          = "7 ";
  chanExp[k_atlas_wv_dgz]            = "ATLAS";
  chanaCC[k_atlas_wv_dgz]  = 0.0   * scale_; 
  chanaCM[k_atlas_wv_dgz]  = -0.055 * scale_; 
  chanaCP[k_atlas_wv_dgz]  = +0.071 * scale_; 
  plotChan[k_atlas_wv_dgz] = true;




  // CDF  http://arxiv.org/abs/0912.4500 Phys.Rev.Lett. 104 (2010) 201801
 // CDF WZ better than WW

//  chanName[k_cdf_ww_dgz]            = "#Deltag^{Z}_{1}";
//   chanMeasurement[k_cdf_ww_dgz]     = "WW";
//   chanLumi[k_cdf_ww_dgz]            = "3.6 ";
//   chanExp[k_cdf_ww_dgz]            = "CDF";
//   chanaCC[k_cdf_ww_dgz]  = 0.0   * scale_; 
//   chanaCM[k_cdf_ww_dgz]  = -0.22 * scale_; 
//   chanaCP[k_cdf_ww_dgz]  = +0.30 * scale_; 
//   plotChan[k_cdf_ww_dgz] = true;


  // CDF http://arxiv.org/abs/1202.6629 Phys.Rev. D86 (2012) 031104
  // almost competative

//   chanName[k_cdf_wz_dgz]            = "#Deltag^{Z}_{1}";
//   chanMeasurement[k_cdf_wz_dgz]     = "WZ";
//   chanLumi[k_cdf_wz_dgz]            = "7.1 ";
//   chanExp[k_cdf_wz_dgz]            = "CDF";
//   chanaCC[k_cdf_wz_dgz]  = 0.0   * scale_; 
//   chanaCM[k_cdf_wz_dgz]  = -0.08 * scale_; 
//   chanaCP[k_cdf_wz_dgz]  = +0.20 * scale_; 
//   plotChan[k_cdf_wz_dgz] = true;



// D0 http://arxiv.org/abs/1208.5458 Phys.Lett. B718 (2012) 451-459

  chanName[k_d0_vv_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_d0_vv_dgz]     = "D0 comb.";
  chanLumi[k_d0_vv_dgz]            = "8.6 ";
  chanSqrtS[k_d0_vv_dgz]          = "1.96 ";
  chanExp[k_d0_vv_dgz]            = "D0";
  chanaCC[k_d0_vv_dgz]  = 0.022   * scale_; 
  chanaCM[k_d0_vv_dgz]  = -0.034 * scale_; 
  chanaCP[k_d0_vv_dgz]  = +0.084 * scale_; 
  plotChan[k_d0_vv_dgz] = true;

// LEP  hep-ex/0212036 and hep-ex/0307056 http://arxiv.org/abs/1302.3415

  chanName[k_lep_ww_dgz]            = "#Deltag^{Z}_{1}";
  chanMeasurement[k_lep_ww_dgz]     = "LEP comb.";
  chanLumi[k_lep_ww_dgz]            = "0.7 ";
  chanSqrtS[k_lep_ww_dgz]          = "0.20 ";
  chanExp[k_lep_ww_dgz]            = "LEP";
  chanaCC[k_lep_ww_dgz]  = -0.016   * scale_; 
  chanaCM[k_lep_ww_dgz]  = -0.054 * scale_; 
  chanaCP[k_lep_ww_dgz]  = +0.021 * scale_; 
  plotChan[k_lep_ww_dgz] = true;

  // CMS

  chan = k_cms_wv13_dkz;
  chanName[chan]            = "#Delta#kappa_{Z}";
  chanMeasurement[chan]     = "WV";
  chanLumi[chan]            = "2.3 ";
  chanSqrtS[chan]           = "13 ";
  chanExp[chan]             = "CMS";
  chanaCC[chan]  = 0.0   * scale_;
  chanaCM[chan]  = -0.040 * scale_;
  chanaCP[chan]  = +0.041 * scale_;
  plotChan[chan] = false;

  chan = k_cms_wv13_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "WV";
  chanLumi[chan]            = "2.3 ";
  chanSqrtS[chan]           = "13 ";
  chanExp[chan]             = "CMS";
  chanaCC[chan]  = 0.0   * scale_;
  chanaCM[chan]  = -0.039 * scale_;
  chanaCP[chan]  = +0.039 * scale_;
  plotChan[chan] = false;

  chan = k_cms_wv13_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "WV";
  chanLumi[chan]            = "2.3 ";
  chanSqrtS[chan]          = "13 ";
  chanExp[chan]            = "CMS";
  chanaCC[chan]  = 0.0   * scale_;
  chanaCM[chan]  = -0.067 * scale_;
  chanaCP[chan]  = +0.066 * scale_;
  plotChan[chan] = false;

  

  
   // CMS WZ 8 TeV
  // http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-014/index.html
  // https://arxiv.org/abs/1609.05721 Submitted to EPJC

  chan = k_cms_wz8_dkz;
  chanName[chan]            = "#Delta#kappa_{Z}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "19.6 ";
  chanExp[chan]            = "CMS";
  chanSqrtS[chan]          = "8 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.21 * scale_; 
  chanaCP[chan]  =  0.25 * scale_;  
  plotChan[chan] = true; 

  chan = k_cms_wz8_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "19.6 ";
  chanSqrtS[chan]          = "8 ";
  chanExp[chan]            = "CMS";
  chanaCC[chan]  = 0.0   * scale_;
  chanaCM[chan]  = -0.018 * scale_;
  chanaCP[chan]  = +0.035 * scale_;
  plotChan[chan] = true;

  chan = k_cms_wz8_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "19.6 ";
  chanSqrtS[chan]          = "8 ";
  chanExp[chan]            = "CMS";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.018 * scale_; 
  chanaCP[chan]  = +0.016 * scale_; 
  plotChan[chan] = true;


  // CMS WZ 13 TeV
  // https://arxiv.org/abs/1901.03428 submitted to JHEP
  // http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-18-002/
 
  chan = k_cms_wz13_dkz;
  chanName[chan]            = "#Delta#kappa_{Z}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "35.9 ";
  chanExp[chan]            = "CMS";
  chanSqrtS[chan]          = "13 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.167 * scale_; 
  chanaCP[chan]  =  0.131 * scale_;  
  plotChan[chan] = true; 

  chan = k_cms_wz13_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "35.9 ";
  chanSqrtS[chan]          = "13 ";
  chanExp[chan]            = "CMS";
  chanaCC[chan]  = 0.0   * scale_;
  chanaCM[chan]  = -0.0137 * scale_;
  chanaCP[chan]  = +0.00828 * scale_;
  plotChan[chan] = true;

  chan = k_cms_wz13_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "WZ";
  chanLumi[chan]            = "35.9 ";
  chanSqrtS[chan]          = "13 ";
  chanExp[chan]            = "CMS";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.0082 * scale_; 
  chanaCP[chan]  = +0.0086 * scale_; 
  plotChan[chan] = true;

  
   // CMS WV 8 TeV
  // http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-14-014/index.htmlhttp://cms-results.web.cern.ch/cms-results/public-results/preliminary-results/SMP-13-008/index.html

  chan = k_cms_wv8_dkz;
  chanName[chan]            = "#Delta#kappa_{Z}";
  chanMeasurement[chan]     = "WV";
  chanLumi[chan]            = "19 ";
  chanExp[chan]            = "CMS";
  chanSqrtS[chan]          = "8 ";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = (-2.0 - 17.0*0.30082992949) * 0.5 * 0.080385 * 0.080385 * scale_; 
  chanaCP[chan]  = (5.7 + 14.0*0.30082992949) * 0.5 * 0.080385 * 0.080385 * scale_;

  chanaCM[chan]  = (-0.0087 - 0.044 * tan2thetaw) * scale_; 
  chanaCP[chan]  = (0.024 + 0.063 *tan2thetaw) * scale_;  

  
  plotChan[chan] = false;// removing conversions with corr matrix  




  
  chan = k_cms_wv8_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "WV (l#nuJ)";
  chanLumi[chan]            = "19 ";
  chanSqrtS[chan]          = "8 ";
  chanExp[chan]            = "CMS";
  chanaCC[chan]  = 0.0   * scale_;
  chanaCM[chan]  = -0.0087 * scale_;
  chanaCP[chan]  = +0.024 * scale_;
  plotChan[chan] = true;

  chan = k_cms_wv8_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "WV (l#nuJ)";
  chanLumi[chan]            = "19 ";
  chanSqrtS[chan]          = "8 ";
  chanExp[chan]            = "CMS";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.011 * scale_; 
  chanaCP[chan]  = +0.011 * scale_; 
  plotChan[chan] = true;

  // ATLAS WVjj and WVJ annlysis
  // https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/STDM-2015-23/

  chan = k_atlas_wvjj8_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "WV (l#nujj)";
  chanLumi[chan]            = "20.2 ";
  chanSqrtS[chan]          = "8 ";
  chanExp[chan]            = "ATLAS";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.022 * scale_; 
  chanaCP[chan]  = +0.022 * scale_; 
  plotChan[chan] = true;


  
  chan = k_atlas_wvJ8_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "WV (l#nuJ)";
  chanLumi[chan]            = "20.2 ";
  chanSqrtS[chan]          = "8 ";
  chanExp[chan]            = "ATLAS";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.013 * scale_; 
  chanaCP[chan]  = +0.013 * scale_; 
  plotChan[chan] = true;



  chan = k_atlas_wvjj8_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "WV (l#nujj)";
  chanLumi[chan]            = "20.2 ";
  chanSqrtS[chan]          = "8 ";
  chanExp[chan]            = "ATLAS";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.027 * scale_; 
  chanaCP[chan]  = +0.045 * scale_; 
  plotChan[chan] = true;

  chan = k_atlas_wvJ8_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "WV (l#nuJ)";
  chanLumi[chan]            = "20.2 ";
  chanSqrtS[chan]          = "8 ";
  chanExp[chan]            = "ATLAS";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.021 * scale_; 
  chanaCP[chan]  = +0.024 * scale_; 
  plotChan[chan] = true;

  // CMS VBF W 13 TeV
  // http://cms-results.web.cern.ch/cms-results/public-results/publications/SMP-17-011/
  //https://arxiv.org/abs/1903.04040 Submitted to EPJC

  chan = k_cms_vbfwvbfz13_dkz;
  chanName[chan]            = "#Delta#kappa_{Z}";
  chanMeasurement[chan]     = "EW qqW,qqZ";
  chanLumi[chan]            = "35.9";
  chanExp[chan]            = "CMS";
  chanSqrtS[chan]          = "13";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.043 * scale_; 
  chanaCP[chan]  =  0.042 * scale_;  
  plotChan[chan] = true;

  chan = k_cms_vbfwvbfz13_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "EW qqW,qqZ";
  chanLumi[chan]            = "35.9";
  chanSqrtS[chan]          = "13";
  chanExp[chan]            = "CMS";
  chanaCC[chan]  = 0.0   * scale_;
  chanaCM[chan]  = -0.021 * scale_;
  chanaCP[chan]  = +0.034 * scale_;
  plotChan[chan] = true;

  chan = k_cms_vbfwvbfz13_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "EW qqW,qqZ";
  chanLumi[chan]            = "35.9";
  chanSqrtS[chan]          = "13";
  chanExp[chan]            = "CMS";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.0071 * scale_; 
  chanaCP[chan]  = +0.0076 * scale_; 
  plotChan[chan] = true;

  // ATLAS EWK Wjj
  // https://arxiv.org/abs/1703.04362 Eur. Phys. J. C 77 (2017) 474
  // https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/STDM-2014-11/
  
  chan = k_atlas_vbfw8_dkz;
  chanName[chan]            = "#Delta#kappa_{Z}";
  chanMeasurement[chan]     = "EW qqW";
  chanLumi[chan]            = "20.2";
  chanExp[chan]            = "ATLAS";
  chanSqrtS[chan]          = "8";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.15 * scale_; 
  chanaCP[chan]  =  0.16 * scale_;  
  plotChan[chan] = true; 
  
  chan = k_atlas_vbfw8_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "EW qqW";
  chanLumi[chan]            = "20.2";
  chanSqrtS[chan]          = "8";
  chanExp[chan]            = "ATLAS";
  chanaCC[chan]  = 0.0   * scale_;
  chanaCM[chan]  = -0.13 * scale_;
  chanaCP[chan]  = +0.12 * scale_;
  plotChan[chan] = true;

  chan = k_atlas_vbfw8_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "EW qqW";
  chanLumi[chan]            = "20.2";
  chanSqrtS[chan]          = "8";
  chanExp[chan]            = "ATLAS";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.053 * scale_; 
  chanaCP[chan]  = +0.042 * scale_; 
  plotChan[chan] = true;

  // ATLAS EWK Zjj
  // https://arxiv.org/abs/1401.7610 JHEP 04 (2014) 031
  // https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/STDM-2013-02/

  chan = k_atlas_vbfz8_lz;
  chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "EW qqZ";
  chanLumi[chan]            = "20.3";
  chanSqrtS[chan]          = "8";
  chanExp[chan]            = "ATLAS";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  = -0.15 * scale_; 
  chanaCP[chan]  = +0.13 * scale_; 
  plotChan[chan] = true;

  // ATLAS 13 TeV WW
  // https://arxiv.org/abs/1905.04242 Submitted to EPCJ
  // https://atlas.web.cern.ch/Atlas/GROUPS/PHYSICS/PAPERS/STDM-2017-24/

  chan = k_atlas_ww13_lz;
    chanName[chan]            = "#lambda_{Z}";
  chanMeasurement[chan]     = "WW";
  chanLumi[chan]            = "36.1";
  chanSqrtS[chan]          = "13";
  chanExp[chan]            = "ATLAS";
  chanaCC[chan]  = 0.0 * scale_; 
  chanaCM[chan]  = -3.4 * 1.5 * g * g *  mw * mw * scale_; 
  chanaCP[chan]  = 3.3 * 1.5 * g * g *  mw * mw * scale_; 
  plotChan[chan] = true;

  chan = k_atlas_ww13_dgz;
  chanName[chan]            = "#Deltag^{Z}_{1}";
  chanMeasurement[chan]     = "WW";
  chanLumi[chan]            = "36.1";
  chanSqrtS[chan]          = "13";
  chanExp[chan]            = "ATLAS";
  chanaCC[chan]  = 0.0   * scale_; 
  chanaCM[chan]  =  -7.4 * 0.5 * mz * mz * scale_;  
  chanaCP[chan]  =  +4.1 * 0.5 * mz * mz * scale_; 
  plotChan[chan] = true;

  }

// define experiments and experiment colors

const int numberExperiments = 6;
vector<string> experiments(numberExperiments);
vector<int> colors(numberExperiments);

experiments[0] = "CMS";
experiments[1] = "ATLAS";
experiments[2] = "CDF";
experiments[3] = "D0";
experiments[4] = "LEP";
experiments[5] = "ATLAS+CMS";


colors[0] = kRed;
colors[1]= kBlue;
colors[2] = 209;
colors[3] = 209;
colors[4] = kBlack;
colors[5] = 221;


// determine limit range and number of measurements and experiments

float range = 0.0;

int types = 0;
int exps = 0;
bool centralValue = false;



for( size_t ii=0; ii<k_nChan; ii++ )
  {
    if (plotChan[ii] == true) {
      // determine limit range, used for x axis

      if (-chanaCM[ii] > range) range = -chanaCM[ii];
      if ( chanaCP[ii] > range) range =  chanaCP[ii];

      // determine number of measurement, used in y axis
      nPlotChan++;
      // determine number of experiments,  used in ledgend
      if (chanExp[ii]=="CMS")   types = types|1;
      if (chanExp[ii]=="ATLAS") types = types|2;
      if (chanExp[ii]=="CDF")   types = types|4;
      if (chanExp[ii]=="D0")   types = types|8;
      if (chanExp[ii]=="LEP")   types = types|16;
      if (chanExp[ii]=="ATLAS+CMS")   types = types|32;
      // determine if a central value is measured for ledgend
      if (chanaCC[ii] != 0.0) centralValue = true;
      
// Concatonate chan results strings

      ostringstream stream1, stream2, stream3;
      stream1.precision(1);
      stream2.precision(1);
      stream3.precision(1);
      stream1 << scientific;
      stream2 << scientific;
      stream3 << scientific;

      if (aqgc_a||aqgc_fs||aqgc_fm||aqgc_ft||catgcg||catgcz||natgcz 
) {
	stream1<< (chanaCC[ii]);    // for fixed point notation
	stream2<<(chanaCM[ii]);    // for fixed point notation
	stream3<<(chanaCP[ii]);    // for fixed point notation
      } else if ( chanName[ii] == "h^{#gamma}_{3}" ||chanName[ii] == "h^{Z}_{3}")  {
	stream1<< (chanaCC[ii]/100.0);    // for fixed point notation
	stream2<<(chanaCM[ii]/100.0);    // for fixed point notation
	stream3<<(chanaCP[ii]/100.0);    // for fixed point notation

      } else if ( chanName[ii] == "h^{#gamma}_{4}" ||chanName[ii] == "h^{Z}_{4}")  {
	stream1<< (chanaCC[ii]/10000.0);    // for fixed point notation
	stream2<<(chanaCM[ii]/10000.0);    // for fixed point notation
	stream3<<(chanaCP[ii]/10000.0);    // for fixed point notation

      } 
      chanResult[ii] = stream2.str() + ", " + stream3.str();

      // Determine channel colors and line types;

      for (int jj = 0; jj < numberExperiments; jj++){
	if (chanExp[ii]==experiments[jj]) chanColor[ii] = colors[jj];
      }
      // if (chanExp[ii]=="CMS") chanColor[ii] = colors[0];
      // if (chanExp[ii]=="ATLAS") chanColor[ii]= kBlack;
      // if (chanExp[ii]=="CDF") chanColor[ii] = 209;
      // if (chanExp[ii]=="D0") chanColor[ii] = 209;
      // if (chanExp[ii]=="LEP") chanColor[ii] = kBlue;

      cout << "Set chan color " << chanColor[ii] << endl;

      if (aqgc&&lineStyles){
	if (chanMeasurement[ii]     == "ss WW") chanLine[ii] = 7;
	if (chanMeasurement[ii]     == "#gamma#gamma#rightarrowWW") chanLine[ii] = 3;
	if (chanMeasurement[ii]     == "W#gamma") chanLine[ii] = 9;
	//if (chanMeasurement[ii]     == "Z#gamma") chanLine[ii] = 9;
	if (chanMeasurement[ii]     == "WW#gamma") chanLine[ii] = 2;
	if (chanMeasurement[ii]     == "WV#gamma") chanLine[ii] = 2;
	if (chanMeasurement[ii]     == "W#gamma#gamma") chanLine[ii] = 2;
	  
      }

    }
  }



    
if (types&1) exps++;
if (types&2) exps++;
if (types&4) exps++;
if (types&8) exps++;
if (types&16) exps++;
if (types&32) exps++;
    

float minRange = -range*1.3*1.3;
float maxRange = range*1.3*3.2;
cout << "Range: " << -minRange << " - " << maxRange << endl;

cout << "Number of experiments: " << exps << ", Number of measurements: " << nPlotChan << endl;

// verbose print
  bool verbose_(false);
  if( verbose_ )
    {
      for( size_t ii=0; ii<k_nChan; ii++ )
	{
	  cout << chanName[ii]
               << chanMeasurement[ii] 
	       << " " << chanaCC[ii]
	       << " : " << chanaCM[ii]
	       << " -- " << chanaCP[ii]
	       << endl;
	}
    }

