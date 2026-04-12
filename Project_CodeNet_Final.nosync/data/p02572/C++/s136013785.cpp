//I am so vegetable
//#define err
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define POB pop_back
#define PUB push_back
#define IN insert
#define ER erase
#define CT count
#define EP empty
#define FI first
#define SE second
#define lsi p<<1
#define rsi p<<1|1
#define lson l,m,lsi
#define rson m+1,r,rsi
#define BE 1,n,1
#define _for(i,a,b) for(int i = (a);i<(b);++i)
#define _rfor(i,a,b) for(int i = (a);i>(b);--i)
#define _sfor(p,st) for(auto &p:st)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1.0);
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll x, ll y) { ll ans = 1; for (; y > 0; y >>= 1) { if (y & 1)ans *= x; x *= x; }return ans; }
ll qpow(ll x, ll y, int MOD) { ll ans = 1; for (; y > 0; y >>= 1) { if (y & 1)ans = ans*x%MOD; x = x*x%MOD; }return ans; }
void exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1;y=0;return;}
    exgcd(b,a%b,x,y);
    ll X=x;
    x=y; y=X-a/b*y;
}
ll inv(ll x, int mod = MOD) { return qpow(x, mod - 2,mod); }
ll m_m(ll a){ return (a%MOD+MOD)%MOD; }

ll pre[200005];
ll a[200005];
signed main() {
  //ifstream cin("E:\\acm dream\\in.in");
  //ofstream cout("E:\\acm dream\\out.out");
  FIO;
  #ifdef err
  double be = clock();
  #endif

  int n;cin>>n;
  _for(i,1,n+1)cin>>a[i];
  _rfor(i,n,0){
    pre[i]=pre[i+1]+a[i];
    pre[i]%=MOD;
  }
  ll ans=0;
  _for(i,1,n+1){
    ans+=a[i]*pre[i+1]%MOD;
    ans%=MOD;
  }
  cout<<ans;


  #ifdef err
  double en = clock();
  cout<<"time: "<<fixed<<setprecision(8)<<en-be;
  #endif
  return 0;
}
/*                                                                                                                
                                    .r17:                                                                                                             
                                    :KQK:                                                                                                             
                                    :5QS:                                                                                                             
                 .   .               7XU:              .:r:.                                                                                          
                   .vQgvi.    .       ..             .i2QgL:.                                                                                         
                    iSBBgv.                          :5RdJ.                                                                                           
                      :jL:      .iuXEdZEggRDbI7.     .i:.                                                                                             
                            .:vbQBBBBBQQQBBBBBBQPY:.       .                                                                                          
                           :SMBBQPJrrii:iiiir7uPQQgUr                                                                                                 
                         .YEMZXsi::i:::iii:::..:ruPQQu.                                                                                               
                         7BQPsri:.::i:rrriiirrr:::vPBDr     .:iri.                                                                                    
                  ..    .IQgYr:::irri:irir71qEPui.:JdQPr  .vKBQQI:                                                                                    
               .i5QRPr. iZB5r::r1qRZXvr:iruPMMQK7::iUBB5. :sI51r.                                                                                     
               .:vIXL:..sBBj:iiv5MBBDIrrirrJXdKj7i::rEBE:                                                                                             
                        2BMr:::ru5Pq2riii::::ir:iriirKBq.                            .vKPv:                                                           
                        jBgv:i:iii:ii:::ii:i:rri:i:irbBU                           :PBBBBBBd:                                                         
                        iBBSr:r77i::LJsriirsbggJr::r1gQ7                          :ZBB1:i1BQQv                                                        
                        .PBRsii777isbBBRdEdQBBMu::iJgQ5i                          vBD:    .DQB7                                                       
                         7gQdui:i:i7KMBQBBBQgX7:::1DB5:..:i:.                    :PQZ:     5BQj                                                       
                    .i7vi:rSgQXv::.::r7su2uv:..iYdQBZ:  .1MBQ7.                  .iZQKi..rjQQX.                                                       
                    7BBRL   vdBBBD2rri:....:i7SRBBXi.    .ru5i.                    .PBBQQQBq:                                                         
                   .:u1r.    .rqBBQBQRZPUUSMBBBBDj.                                .bBBBBBQv                                                          
                                .:sXgQBBBBBQDUr..                                  5Bg7.7ZBMi                                                         
                                     ....:..    .:.                               :QQX. .1QBBX:                                                       
                                  ...          .ugEv:.                            vQBu:  .uQBBBv.                                                     
                                 iPB5:          :JDBEr                           .JBBu:...:YZBQBM7.                                                   
                                 sBQY.           .r5dr                            sBBqr.....iLDBBBQsi.                                                
                                .rLr                                              iQBgvi......:v5ERBBBQQDD5u7:.                                       
                                                                                  :BBBPr:.....  ..irj5DBBBBBBBBQ2.                                    
                                                                                   7QBBXi::.........   .:iiLXQBBBBU.                                  
                                                                                    :2BBgur::::.:.:......   .:rvdBBRr                                 
                                                                                      :qBBP7:::i:i::::::::.......rXBBgr                               
                                                                                        QBgvi:i::::..:::::::::....:7RBBu.                             
                                                                                       rQBQPjLri:......:.:.:::.:.:..iSBBS.                            
                                                                                      7BBQBRQBBQPsr:.. ...:.:::::.....7QBL                            
                                                                                      iBBbjvvSMBQBBM5L:......:::.:....:SBRr                           
                                                                                      :DB57.   .i7XMBBBPu:. ..::::::...rqQg:                          
                                                                                   .vEBBBBBQPr     .iUgBBBKi.. ..::i...:jQBv                          
                                                                                 .IBBBBLr1gQBBBPr     .iSQBBgY:...:::..:jRBb.                         
                                                                               .7QBBPL.     .1BBBRUi     .rMBBgY.....:.:rPBM.                         
                                                                              .XBBB7           :XBBBBI.     :5BBPr....::7PBD.                         
                                                                              sBBg:              .:JgBQK:     rgBB1i.. :7ZBg:                         
                                                                             .QQI                    :PQBPi    .1BBPr. .LDBE.                         
                                                                             7BM:                      :SBBSi    idBgv..7BQ1                          
                                                                            .EB2.               ::.      :5BB5:   .5BQurqBQj:                         
                                                                            2BBJ.            v5qui         LZBgr   .1BBQBBBBQdvi:i7r.                 
                                                                          .vBBQ7.          .rIDX7. ..       .LQBP.  .7QBBPLEBBBBBBBBQY.               
                                                                       .isXZd5i..        .vP:. rZ7 :j5:       :DBRi   vBBs  :SBBQBgQBBRr              
                                                                     iqQBPv.              7I:.YY:    :r7i.     .jMRr  .SBZ.        .XBBu.             
                                                                   iXQdv.            .:YsjPQSJ..s:  .:rKQU.  .   7Dg7..2BB:      :jXQBQv              
                                                          ..:r7iisQBQi    .vji.       :ir:rUs   .JPPq7:.:.       iZBQgBBBI.      jBBBD7.              
                                                       .7PBBQBBBBBQj   .vgQQsi.            ::    sQQ2:           rQBBBBgr        YBBgJ                
                                                     :XQBBBBBdgQBS.  :bQBBBj                :v:iZK. .r:   ..    .UBBD57.         sBBgi                
                                                   :1BBBBQ57i5ZQ5   vBBd2KEQESi.            .sPdr        .     .PBQ7            .gBB5.                
                                                  :5BBBKv.  .PQ1.  2QPr  .:vqMBQgI7:.                         7RBB5             1QBQ7                 
                                         .       iqBQQji.  ..PE: :PBJ.....   :rUqBBBBQKr                    :MBBD7.           .igBBd.                 
                                               .7dBBBJ:.....:S5..UBEi .::.........:r2EBBBgu.              :DBBBr             :IZBBML.                 
                                            .ijgQBQPL:...:...77  7dDr....:::.:.......:i7XBBZi:.     .:rYSgBBB1              .SBBB2:.                  
                                      ..:isPBBBBBg1i:.:.:...::.  .vKK7:...::..:::........:LPRBBQRggEQQBBBBEi               .sgBBI.                    
                                    .r2gQBBBQQP27i....:::::::7.   iZRKr:.:::::...:.........::vIgQBBBQBBBBRIr::..      .::.  .SBBL.                    
                                  .:JEBQBRE57::.........:::::iiLS5EQXr:...:.:.:.:::...:::.......rIMBBdLrsgBQBBBQBRRgZEBBBBU:7bBBd:                    
                                  ibQBQSi:.   .....:::::.:::.:iIbqJi...:.:...:.:.:.:...:.:.::....:7KbU.   :1XMBBBBBBBBQBQBBBBBBRv.                    
                                 .rZBQY.....:::::::::::::::.:.:.....:::::::.::::::::::..:.:.:.:....:YPgIi     ..::r7v7i.:r1Squ7:                      
                                  .r7i...:::::.:.:::::::::::::::.:::::::::.::i:i:i::::::::::::.:.....7dBQgv.                                          
                                                 .............:.::...   ........................:....:ivEBRji                                         
                                                               . .                                 .    .i::.                                         
                                                                                                                                                      
                           L1.   :i:::::...  .::::::.....:::::..      7U     .....             is.           ............. .                          
                           Ed    7Dbqdb2QBj  :PEZKKXP2ZBRKKPDZK7. .:iigMi:: sDRZZbRv   .irri7rrqBUrrrirri   .vbDMEZMQMgqqPQBd:                        
                        i77Bb7vi       r5v.           uP.         :JSPBBXZY      .Mj   .vPS5YKIgBSsUUbq5v.     . .      .UZXr.                        
                        :rQQ7iQZ.     UKi            vB2              sY         .Qv      rS.  rB:  .5r               .jZj.                           
                          D7  P5     KB:           iXBBv rL:     .:77LgQrvj:rZXKbQB7       1j  rB.  Y5.             .SZY.                             
                         vE. .g7.YdSPQBJUd5i.    igBriQi ibg5.   .iv7:2Q2rr.XBi....    :UuvUDriUBsiKBq7sY.          idu                               
                        .gg. jE. ::::Kgr.:..  .7EQu. :Qv   iIBq:   r7 .b:   1S     ..  :YJv7r1BBBBMjirvsJr          :Es                               
                         .rXZB:      IR.     :QQU.   iBr     rd7.  2S .MBbv.Xd    rBY       .r:sMiiL.               :Pj                               
                           uQB2:     2g:     ..      iBv          .gM.:E.   7QgqXXMK.    .iPU: rB. .2Xi.            :dY                               
                          vEY.jEv.   2Q:             rBL         .5PIqBB7     .::..    :1bb7   LB:   7dDX:          :bu                               
                        igP:      vddBd.             rBX         .5L  7PgZPdEPIS2SXE1. YIr     2Br     rUL.     .JDgDBY                                                                                                                                                                                          
*/