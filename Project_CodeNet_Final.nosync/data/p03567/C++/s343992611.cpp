//# define FLAG
///delet....................................
#define GGG
#include    <bits/stdc++.h>
using namespace std;
#define     FOR(i,a,n)              for(register int i=a;i<=n;++i)
#define     FIR(i,n,a)              for(register int i=n;i>=a;--i)
#define     FOR_(i,a,n)             FOR(i,a,n-1)
#define     FIR_(i,n,a)             FIR(i,n-1,a)
#define     VOR(i,a)                for(int i=0,n=a.size();i<n;++i)
#define     SOR(i,a)                for(auto i=a.begin();i!=a.end();++i)
#define     all(a)                  (a).begin(),(a).end()
#define     vlb(a,n)                (lower_bound(all(a),n)-a.begin())
#define     vub(a,n)                (lower_bound(all(a),n)-a.begin())
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     sz(a)                   ((int)a.size())
#define     pw(x)                   (1ll<<(x))
#define     lowbit(x)               ((x)&(-x))
#define     bug                     puts("H");
#pragma     comment(linker,"/STACK:1024000000,1024000000")
#define     debug(...)              fprintf(stderr,__VA_ARGS__)
#define     IOS                     ios::sync_with_stdio(false)
#define     lch                     p<<1,l,mid
#define     rch                     p<<1|1,mid+1,r
#define     queue_                  priority_queue
#define     pb                      push_back
#define     mp                      make_pair
#define     lb                      lower_bound
#define     ub                      upper_bound
#define     ff                      first
#define     ss                      second
typedef     long long               LL;
typedef     unsigned long long      ULL;
typedef     pair<int,int>           PII;
typedef     pair<LL,LL>             PLL;
typedef     pair<double,double>     PDD;
typedef     vector<PII>             VPI;
typedef     vector<PLL>             VPL;
typedef     vector<PDD>             VPD;
typedef     vector<int>             VI;
typedef     vector<LL>              VL;
typedef     vector<double>          VB;
const       int                     dx[]={1,0,-1,0,1,-1,1,-1};
const       int                     dy[]={0,1,0,-1,1,-1,-1,1};
const       long long               LINF=0xfcfcfcfcfcfcfcfll;
const       double                  pi=3.141592653589793238462643383279502881l;
const       double                  ee=2.718281828459;
const       double                  eps=0.00000001;
const       int                     INF=0x3f3f3f3f;
const       int                     MOD=1000000007;
inline LL powmod(LL x,LL n,LL mod=MOD,LL res=1){for(; n; x*=x%mod,n>>=1)if(n&1)res*=x%mod;return res;}
template<typename T>inline T max(T a,T b,T c){return max(a,max(b,c));}
template<typename T>inline T min(T a,T b,T c){return min(a,min(b,c));}
template<typename T>inline T max(T a,T b,T c,T d){return max(a,max(b,c,d));}
template<typename T>inline T min(T a,T b,T c,T d){return min(a,min(b,c,d));}
inline int div_10(int n,int q=0){q=(n>>1)+(n>>2),q+=(q>>4),q+=(q>>8),q+=(q>>16),q>>=3;return q+(n-(((q<<2)+q)<<1)>9);}
inline LL div_10(LL n,LL q=0){q=(n>>1)+(n>>2),q+=(q>>4),q+=(q>>8),q+=(q>>16),q+=(q>>32),q>>=3;return q+(n-(((q<<2)+q)<<1)>9);}
#ifdef GGG
#define     hr                      ptc('\n')
#define     kb                      ptc(' ')
inline char gtc(){static char buf[1000000],*p1=buf-1,*p2=buf-1;return p1==p2&&(p2=(p1=buf-1)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*++p1;}
inline LL read(){char ch=gtc();while(!(ch>='0'&&ch<='9'||ch=='-'))ch=gtc();LL sum=0,flag=(ch=='-'?(ch=gtc()):0);while(ch>='0'&&ch<='9')sum=(sum<<3)+(sum<<1)+ch-'0',ch=gtc();return flag?-sum:sum;}
static char bufout[1000005],*chout=bufout-1;
inline void ptc(char ch){if(*++chout=ch,chout==bufout+1000000)fwrite(bufout,1,chout-bufout+1,stdout),chout=bufout-1;}
template<typename T>inline void out(T x){if(x<0)ptc('-'),x=-x;if(x>9)out(div_10(x));ptc(x%10+'0');}
inline void write(){fwrite(bufout,1,chout-bufout+1,stdout);}
#else
#define     hr                      putchar('\n')
#define     kb                      putchar(' ')
inline LL read(){char ch=getchar();while(!(ch>='0'&&ch<='9'||ch=='-'))ch=getchar();LL sum=0,flag=(ch=='-'?(ch=getchar()):0);while(ch>='0'&&ch<='9')sum=(sum<<3)+(sum<<1)+ch-'0',ch=getchar();return flag?-sum:sum;}
template<typename T>inline void out(T x){if(x<0)putchar('-'),x=-x;if(x>9)out(div_10(x));putchar(x%10+'0');}
#endif
/**___________________________head____________________________**/

const int N=10005;
int a[200];

int main() {
    IOS;
#ifdef FLAG
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
    string b;
    int flag=1;
    cin>>b;
    FOR_(i,0,b.size()-1) {
        if(b[i]=='A'&&b[i+1]=='C') {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
#ifdef GGG
    write();
#endif
    return 0;
}










///delete FLAG...................................................



