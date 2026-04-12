#pragma GCC optimize(2)


#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define rusha scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);
#define rushb scanf("%d",&t);while(t--)
#define debug(x) cout<<" L-B-W-- "<<x<<" --N-B\n"
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vii vector<int>
#define fi first
#define se second
#define mem(a,b) memset(a,b,sizeof a)
#define all(x) (x.begin(),x.end())
#define judgef printf("%s\n",f?"Yes":"No")
#define Judgef printf("%s\n",f?"YES":"NO")
#define sz(x) ((int)(x).size())
#define sf(x) (sizeof(x))
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
///miao a

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef unsigned int uint;
mt19937_64 mrand64(random_device{}());
//mt19937_64 mrand64(chrono::steady_clock::now().time_since_epoch().count());
ll rng(ll x){return (ull)mrand64() % x;}
const double pai = acos(-1.0);
const double eps = 1e-8;
//const int mod=998244353;
const int mod=1e9+9;
//const int mod=100000429;
//const int inf=1e9+9;
const ll inf=0x7f7f7f1234abcd;
const int maxn=2e5+10;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
inline ll ksm(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y>>=1;}return res;}
inline ll inv(ll a,ll p){if(a==1)return 1;return (p-p/a)*inv(p%a,p)%p;}
inline ll lcm(ll a,ll b){return a * b / __gcd(a, b);}

int t,n,m,k;
//ll a[maxn];
int main(){
    scanf("%d",&n);
    printf("%s\n",n>=30?"Yes":"No");
    return 0;
}
/*

*/

//                  .,:,,,                                        .::,,,::
//                .::::,,;;,                                  .,;;:,,....:i:
//                :i,.::::,;i:.      ....,,:::::::::,....   .;i:,.  ......;i.
//                :;..:::;::::i;,,:::;:,,,,,,,,,,..,.,,:::iri:. .,:irsr:,.;i.
//                ;;..,::::;;;;ri,,,.                    ..,,:;s1s1ssrr;,.;r,
//                :;. ,::;ii;:,     . ...................     .;iirri;;;,,;i,
//                ,i. .;ri:.   ... ............................  .,,:;:,,,;i:
//                :s,.;r:... ....................................... .::;::s;
//                ,1r::. .............,,,.,,:,,........................,;iir;
//                ,s;...........     ..::.,;:,,.          ...............,;1s
//               :i,..,.              .,:,,::,.          .......... .......;1,
//              ir,....:rrssr;:,       ,,.,::.     .r5S9989398G95hr;. ....,.:s,
//             ;r,..,s9855513XHAG3i   .,,,,,,,.  ,S931,.,,.;s;s&BHHA8s.,..,..:r:
//            :r;..rGGh,  :SAG;;G@BS:.,,,,,,,,,.r83:      hHAcceptedHM3..,,,,.ir.
//           ,si,.1GS,   sBMAAX&MBMB5,,,,,,:,,.:&8       3@HAcceptedH#X,.,,,,,,rr
//           ;1:,,SH:   .A@&&B#&8H#BS,,,,,,,,,.,5XS,     3@MAccepted#As..,,,,:,is,
//          .rr,,,;9&1   hBHHBB&8AMGr,,,,,,,,,,,:h&&9s;   r9Accepted9:  . .,,,,;ri.
//          :1:....:5&XSi;r8BMBHHA9r:,......,,,,:ii19GG88899XHHH&GSr.      ...,:rs.
//          ;s.     .:sS8G8GG889hi.        ....,,:;:,.:irssrriii:,.        ...,,i1,
//          ;1,         ..,....,,isssi;,        .,,.                      ....,.i1,
//          ;h:               i9HHBMBBHAX9:         .                     ...,,,rs,
//          ,1i..            :A#MBBBBMHB##s                             ....,,,;si.
//          .r1,..        ,..;3BMBBBHBB#Bh.     ..                    ....,,,,,i1;
//           :h;..       .,..;,1XBMMMMBXs,.,, .. :: ,.               ....,,,,,,ss.
//            ih: ..    .;;;, ;;:s58A3i,..    ,. ,.:,,.             ...,,,,,:,s1,
//            .s1,....   .,;sh,  ,iSAXs;.    ,.  ,,.i85            ...,,,,,,:i1;
//             .rh: ...     rXG9XBBM#M#MHAX3hss13&&HHXr         .....,,,,,,,ih;
//              .s5: .....    i598X&&A&AAAAAA&XG851r:       ........,,,,:,,sh;
//              . ihr, ...  .         ..                    ........,,,,,;11:
//                 ,s1i. ...  ..,,,..,,,.,,.,,.,..       ........,,.,,.;s5i.
//                  .:s1r,......................       ..............;shs,
//                  . .:shr:.  ....                 ..............,ishs.
//                      .,issr;,... ...........................,is1s;.
//                         .,is1si;:,....................,:;ir1sr;,
//                            ..:isssssrrii;::::::;;iirsssssr;:..
//                                 .,::iiirsssssssssrri;;:.
