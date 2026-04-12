//# define FLAG
///delet....................................
#define GGG
#include    <bits/stdc++.h>
using namespace std;
#define     FOR(i,a,n)      for(register int i=a;i<=n;++i)
#define     FIR(i,n,a)      for(register int i=n;i>=a;--i)
#define     FOR_(i,a,n)     FOR(i,a,n-1)
#define     FIR_(i,n,a)     FIR(i,n-1,a)
#define     VOR(i,a)        for(register int i=0,n=a.size();i<n;++i)
#define     SOR(i,a)        for(register auto i=a.begin();i!=a.end();++i)
#define     all(a)          (a).begin(),(a).end()
#define     vlb(a,n)        (lower_bound(all(a),n)-a.begin())
#define     vub(a,n)        (lower_bound(all(a),n)-a.begin())
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(a)           ((int)a.size())
#define     pw(x)           ((LL)1<<(x))
#define     lowbit(x)       ((x)&(-x))
#define     bug             puts("H");
#pragma     comment(linker, "/STACK:1024000000,1024000000")
#define     debug(...)      fprintf(stderr,__VA_ARGS__)
#define     IOS             ios::sync_with_stdio(false)
#define     lch             p<<1,l,mid
#define     rch             p<<1|1,mid+1,r
#define     queue_          priority_queue
#define     pb              push_back
#define     mp              make_pair
#define     lb              lower_bound
#define     ub              upper_bound
#define     ff              first
#define     ss              second
typedef     long long               LL;
typedef     unsigned long long      ULL;
typedef     pair<int,int>           PII;
typedef     vector<int>             VI;
typedef     vector<PII>             VII;
const     int           dx[]= { 1, 0,-1, 0, 1,-1, 1,-1};
const     int           dy[]= { 0, 1, 0,-1, 1,-1,-1, 1};
const     long long     LINF=0xfcfcfcfcfcfcfcfll;
const     double        pi=3.141592653589793238462643383279502881l;
const     double        ee=2.718281828459;
const     double        eps=0.00000001;
const     int           INF=0x3f3f3f3f;
const     int           MOD=1000000007;
inline LL powmod(LL x,LL n,LL mod=MOD,LL res=1) { for(; n; x=x*x%mod,n>>=1)if(n&1)res=res*x%mod; return res; }
template<typename T>inline T max(T a,T b,T c) { return max(a,max(b,c)); }
template<typename T>inline T min(T a,T b,T c) { return min(a,min(b,c)); }
template<typename T>inline T max(T a,T b,T c,T d) { return max(a,max(b,c,d)); }
template<typename T>inline T min(T a,T b,T c,T d) { return min(a,min(b,c,d)); }
inline int div_10(int n,int q=0) { q=(n>>1)+(n>>2),q+=(q>>4),q+=(q>>8),q+=(q>>16),q>>=3; return q+(n-(q<<3)-(q<<1)>9); }
inline LL div_10(LL n,LL q=0) { q=(n>>1)+(n>>2),q+=(q>>4),q+=(q>>8),q+=(q>>16),q+=(q>>32),q>>=3; return q+(n-(q<<3)-(q<<1)>9); }
static char bfi[1000000],*ci=bfi-1,*cl=bfi-1,bfo[1000000],*co=bfo-1,chr;
inline bool dig() { return (chr>='0'&&chr<='9')?1:0; }
#ifdef GGG
#define     hr              ptc('\n')
#define     kb              ptc(' ')
inline char gtc() { return ci==cl&&(cl=(ci=bfi-1)+fread(bfi,1,1000000,stdin),ci==cl)?EOF:*++ci; }
inline void readbit(double &ret,double bit=0.1) { if(chr=gtc(),dig())ret+=(chr-'0')*bit,readbit(ret,bit*0.1); }
inline LL read() { while(chr=gtc(),!(dig()||chr=='-')); LL sum=0,flag=(chr=='-'?(chr=gtc()):0); while(dig())sum=(sum<<3)+(sum<<1)+chr-'0',chr=gtc(); return flag?-sum:sum; }
inline bool scan(LL &res,bool flag=0,bool f=0,LL sum=0) { while(chr=gtc(),!(dig()||(chr=='-'?(chr=gtc(),flag=1):0))); while(dig())sum=(sum<<3)+(sum<<1)+chr-'0',f=1,chr=gtc(); return f?(res=flag?-sum:sum,1):0; }
inline bool scan(double &ret,bool flag=0,LL sum=0) { while(chr=gtc(),!(dig()||(chr=='-'?(chr=gtc(),flag=1):0))); while((dig())?1:(ret=sum,0))sum=(sum<<3)+(sum<<1)+chr-'0',chr=gtc(); if(chr=='.')readbit(ret); return ret?(ret=flag?-ret:ret):0; }
inline bool scan(char *p,bool f=0) { while(chr=gtc(),chr==' '||chr=='\n'); while(chr!='\n'&&chr!=EOF)*p++=chr,chr=gtc(),f=1; return (*p=0,f); }
inline void ptc(char ch) { if(*++co=ch,co==bfo+999999)fwrite(bfo,1,co-bfo+1,stdout),co=bfo-1; }
template<typename T>inline void out(T x) { if(x<0)ptc('-'),x=-x; if(x>9)out(div_10(x)); ptc(x%10+'0'); }
inline void out(char *p) { while(*p)ptc(*p++); }
inline void write() { fwrite(bfo,1,co-bfo+1,stdout),co=bfo-1; }
#else
#define     ptc             putchar
#define     hr              ptc('\n')
#define     kb              ptc(' ')
inline void readbit(double &ret,double bit=0.1) { if(chr=getchar(),dig())ret+=(chr-'0')*bit,readbit(ret,bit*0.1); }
inline LL read() { while(chr=getchar(),!(dig()||chr=='-')); LL sum=0,flag=(chr=='-'?(chr=getchar()):0); while(dig())sum=(sum<<3)+(sum<<1)+chr-'0',chr=getchar(); return flag?-sum:sum; }
inline bool scan(LL &res,bool flag=0,bool f=0,LL sum=0) { while(chr=getchar(),!(dig()||(chr=='-'?(chr=getchar(),flag=1):0))); while(dig())sum=(sum<<3)+(sum<<1)+chr-'0',f=1,chr=getchar(); return f?(res=flag?-sum:sum,1):0; }
inline bool scan(double &ret,bool flag=0,LL sum=0) { while(chr=getchar(),!(dig()||(chr=='-'?(chr=getchar(),flag=1):0))); while((dig())?1:(ret=sum,0))sum=(sum<<3)+(sum<<1)+chr-'0',chr=getchar(); if(chr=='.')readbit(ret); return ret?(ret=flag?-ret:ret):0; }
inline bool scan(char *p,bool f=0) { while(chr=getchar(),chr==' '||chr=='\n'); while(chr!='\n'&&chr!=EOF)*p++=chr,chr=getchar(),f=1; return (*p=0,f); }
template<typename T>inline void out(T x) { if(x<0)putchar('-'),x=-x; if(x>9)out(div_10(x)); putchar(x%10+'0'); }
inline void out(char *p) { while(*p)putchar(*p++); }
#endif
/**___________________________head____________________________**/

int main() {
    IOS;
#ifdef FLAG
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
    int a,b,c;
    cin>>a>>b>>c;
    if(a/(b+c)*(b+c)+c<=a)cout<<a/(b+c)<<endl;
    else cout<<max(0,a/(b+c)-1)<<endl;
#ifdef GGG
    write();
#endif // GGG
    return 0;
}










///delete FLAG...................................................




