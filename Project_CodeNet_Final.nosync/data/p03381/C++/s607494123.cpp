#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <map>
#include <new>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_set>
# include <unordered_map>
# else
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using tr1::unordered_map;
using tr1::unordered_set;
# endif
# else
# include <unordered_map>
# include <unordered_set>
# endif
#define    FOR(i,a,n)       for(register int i=(a),_=(n)+1;i<_;++i)
#define    FIR(i,n,a)       for(register int i=(n),_=(a)-1;i>_;--i)
#define    all(a)           (a).begin(),(a).end()
#define    vlb(a,n)         (lower_bound(all(a),n)-(a).begin())
#define    vub(a,n)         (upper_bound(all(a),n)-(a).begin())
#define    vlbx(a,n)        ((a)[(lower_bound(all(a),n)-(a).begin())])
#define    vubx(a,n)        ((a)[(upper_bound(all(a),n)-(a).begin())])
#define    reunique(a)      (a).resize(unique(all(a))-(a).begin())
#define    mem(a,b)         memset((a),(b),sizeof(a))
#define    sz(x)            (int((x).size()))
#define    lowbit(x)        ((x)&(-x))
#define    lch              p<<1,l,mid
#define    rch              p<<1|1,mid+1,r
#define    ll               (p<<1)
#define    rr               (p<<1|1)
#define    queues           priority_queue
#define    pb               push_back
#define    mp(a,b)          make_pair((a),(b))
#define    lb               lower_bound
#define    ub               upper_bound
#define    ff               first
#define    ss               second
//#pragma    comment(linker, "/STACK:1024000000,1024000000")
//__attribute__((optimize("-O2")))
typedef    long long        LL;
typedef    pair<int,int>    PII;
typedef    pair<LL,LL>      PLL;
typedef    vector<char>     VB;
typedef    vector<int>      VI;
typedef    vector<LL>       VL;
typedef    vector<PII>      VII;
typedef    vector<PLL>      VLL;
// Fast max and min *******************************************************************************
#define max(...) _max(__VA_ARGS__)
#define min(...) _min(__VA_ARGS__)
template<class T>inline T _max(T a,T b) { return a>b?a:b; }
template<class T>inline T _min(T a,T b) { return a<b?a:b; }
template<class T>inline T _max(T a,T b,T c) { return _max(a,_max(b,c)); }
template<class T>inline T _min(T a,T b,T c) { return _min(a,_min(b,c)); }
template<class T>inline T _max(T a,T b,T c,T d) { return _max(a,_max(b,c,d)); }
template<class T>inline T _min(T a,T b,T c,T d) { return _min(a,_min(b,c,d)); }
// Fast I/O ***************************************************************************************
#define Buff 100000
inline char gtc() { static char bfi[Buff],*ci=bfi-1,*cl=ci; return ci==cl&&(cl=(ci=bfi-1)+fread(bfi,1,Buff,stdin),ci==cl)?EOF:*++ci; }
void readbit(double &ret,double bit=0.1,char chr=0) { if(chr=gtc(),isdigit(chr))ret+=(chr^'0')*bit,readbit(ret,bit*0.1); }
inline bool _read(int &res,char flag=0,int sum=0,char chr=0) { while(chr=gtc(),!(isdigit(chr)||(chr^'-'?0:(chr=gtc(),flag=1)))) if(!~chr) return 0; while(isdigit(chr)) sum=(sum+(sum<<2)<<1)+(chr^'0'),chr=gtc(); return (res=flag?-sum:sum,1); }
inline bool _read(LL &res,char flag=0,LL sum=0,char chr=0) { while(chr=gtc(),!(isdigit(chr)||(chr^'-'?0:(chr=gtc(),flag=1)))) if(!~chr) return 0; while(isdigit(chr))sum=(sum+(sum<<2)<<1)+(chr^'0'),chr=gtc(); return (res=flag?-sum:sum,1); }
inline bool _read(double &ret,char flag=0,LL sum=0,char chr=0) { while(chr=gtc(),!(isdigit(chr)||(chr^'-'?0:(chr=gtc(),flag=1)))) if(!~chr) return 0; while((isdigit(chr)))sum=(sum+(sum<<2)<<1)+(chr^'0'),chr=gtc(); if(ret=sum,!(chr^'.'))readbit(ret); return (ret=flag?-ret:ret,1); }
inline bool _read(char &ch,char chr=0) { while(chr=gtc(),(chr==' ')||(chr=='\n')||!~chr) if(!~chr) return 0; return ch=chr; }
inline bool _read(char *p,char chr=0) { while(chr=gtc(),(chr==' ')||(chr=='\n')||!~chr) if(!~chr) return 0; while(chr^'\n'&&~chr)*p++=chr,chr=gtc(); return !(*p=0); }
template<class T,class U>inline bool _read(pair<T,U> &res) { return _read(res.ff),_read(res.ss); }
inline void ptc(char ch=0) { static char bfo[Buff],*co=bfo-1,*coe=co+Buff; !ch||(*++co=ch,co==coe)?fwrite(bfo,1,co-bfo+1,stdout),co=bfo-1:0; }
inline void _out(bool x) { ptc(x?'1':'0'); }
void _out(int x) { if(x<0)ptc('-'),x=-x; if(x>9)_out(x/10); ptc(x%10^'0'); }
void _out(LL x) { if(x<0)ptc('-'),x=-x; if(x>9)_out(x/10); ptc(x%10^'0'); }
inline void _out(double x,int n=6) { if(x<0)ptc('-'),x=-x; _out((LL)x),x-=(LL)x,ptc('.'); while(n--)x*=10; _out(LL(x+0.5)); }
inline void _out(const char ch) { ptc(ch); }
inline void _out(const char *p) { while(*p)ptc(*p++); }
template<class T,class U>inline void _out(pair<T,U> x) { _out(x.ff),_out(' '),_out(x.ss); }
// Local input and debug **************************************************************************
#ifndef ONLINE_JUDGE
#define _read _scan
inline bool _scan(int &res) { return scanf("%d%*c",&res)>0; }
inline bool _scan(LL &res) { return scanf("%lld%*c",&res)>0; }
inline bool _scan(double &ret) { return scanf("%lf%*c",&ret)>0; }
inline bool _scan(char &ch) { return scanf("%c%*c",&ch)>0; }
inline bool _scan(char *p) { return scanf("%s%*c",p)>0; }
template<class T,class U>inline bool _scan(pair<T,U> &res) { return _scan(res.ff),_scan(res.ss); }
inline void _debug_() {}
inline void _debug(bool x) { _out(x); }
inline void _debug(int x) { _out(x); }
inline void _debug(LL x) { _out(x); }
inline void _debug(double x) { _out(x); }
inline void _debug(const char ch) { _out(ch); }
inline void _debug(const char *p) { _out(p); }
template<class T,class U>inline void _debug(pair<T,U> x) { _out('('),_out(x.ff),_out(','),_out(x.ss),_out(')'); }
template<class T,class ...U>void _debug_(T head,U ...tail) { _out(' '),_debug(head),_debug_(tail...); }
template<class ...T>inline void debug(T ...tail) { static int cnt=0; _debug_("#####",++cnt,'|',tail...,'\n'),ptc(); }
#endif
// Encapsulation I/O ******************************************************************************
#ifndef ONLINE_JUDGE
struct basic_read { bool lock,flag; basic_read():lock(1) {} void tie(bool x) { lock=x; } template<class T>basic_read operator>>(T &x) { return flag=(lock?ptc(),_read(x):_read(x)),*this; } template<class T> basic_read operator >> (T *x) { return flag=(lock?ptc(),_read(x):_read(x)),*this; } operator void *() const { return flag?(void*)this:0; } } Read;
#else
struct basic_read { bool flag; template<class T>basic_read operator>>(T &x) { return flag=_read(x),*this; } template<class T> basic_read operator >> (T *x) { return flag=_read(x),*this; } operator void *() const { return flag?(void*)this:0; } } Read;
#endif
struct basic_out { basic_out operator<<(const char *x) { return _out(' '),_out(x),*this; } template<class T>basic_out operator<<(T x) { return _out(x=='\n'&&sizeof(x)==1?x:(_out(' '),x)),*this; } } out_base;
struct base_out { template<class T>basic_out operator<< (T x) { return _out(x),out_base; } } Out;
// STL other **************************************************************************************
template<class T,class U>inline istream&operator>>(istream&os,pair<T,U>&p) { return os>>p.first>>p.second; }
template<class T,class U>inline pair<T,U>operator+(const pair<T,U>&p1,const pair<T,U>&p2) { return mp(p1.ff+p2.ff,p1.ss+p2.ss); }
template<class T,class U>inline pair<T,U>&operator+=(pair<T,U>&p1,const pair<T,U>&p2) { p1.ff+=p2.ff,p1.ss+=p2.ss; return p1; }
template<class T,class U>inline pair<T,U>operator-(const pair<T,U>&p1,const pair<T,U>&p2) { return mp(p1.ff-p2.ff,p1.ss-p2.ss); }
template<class T,class U>inline pair<T,U>&operator-=(pair<T,U>&p1,const pair<T,U>&p2) { p1.ff-=p2.ff,p1.ss-=p2.ss; return p1; }
// Useful constants *******************************************************************************

const int       primes[7] = {24443, 100271, 1000003, 1000333, 5000321, 98765431, 1000000123};
const int       dx[]={ 0, 1, 0,-1, 0, 1,-1, 1,-1};
const int       dy[]={-1, 0, 1, 0,-1, 1,-1,-1, 1};
#define ee      2.718281828459
#define eps     0.00000001
#define fftmod  998244353
#define INF     0x3f3f3f3f
#define LINF    0xfcfcfcfcfcfcfcfll
#define MOD     1000000007
#define pi      3.14159265358979323846l
// My function ************************************************************************************
inline int myrand(int mod) { return ((LL)rand()<<32^(LL)rand()<<16^rand())%mod; }
inline int rand(int a,int b) { return a+myrand(b-a+1); }
inline void normmod(LL &x,LL mod) { x%=mod; if(x<0)x+=mod; }
#if INTPTR_MAX==INT32_MAX or !defined(__SIZEOF_INT128__)
inline LL mulmod(LL x,LL n,LL mod,LL res=0) { for(normmod(x,mod),normmod(n,mod); n; x<<=1,res>=mod?res-=mod:0,x>=mod?x-=mod:0,n>>=1)n&1?res+=x:0; return res; }
#else
inline LL mulmod(LL x,LL n,LL mod) { return __int128(x)*n%mod; }
#endif
inline LL pmod(LL x,LL n,LL mod=MOD,LL res=1) { for(normmod(x,mod); n; x=mod?x*x%mod:x*x,n>>=1)n&1?res=mod?res*x%mod:res*x:0; return res; }
inline LL pmmod(LL x,LL n,LL mod=MOD,LL res=1) { for(normmod(x,mod); n; x=mulmod(x,x,mod),n>>=1)n&1?res=mulmod(res,x,mod):0; return res; }
template<class T>inline T gcd(T a,T b) { while(b) { T t=a%b;a=b;b=t; } return a; }
template<class T>inline T lcm(T a,T b) { return a/gcd(a,b)*b; }
//*************************************************************************************************

int teble();
int main() {
#if 1
    #define cin Read
    #define cout Out
    #define endl '\n'
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
#ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
    teble();
    ptc();
    return 0;
}
//***************************************************************
//***************************************************************
//***************************************************************
/**________________________code.begin_________________________**/

const int N=1e6+5;
//int a[N];
PII a[N];
map<int ,int > m;

bool cmp(PII i,PII j) {
    return i.ss<j.ss;
}

int teble() {
    int n,x;
    cin>>n;
    FOR(i,1,n)cin>>x,a[i]=mp(i,x);
    sort(a+1,a+n+1,cmp);
    FOR(i,1,n)m[a[i].ff]=i;//debug(a[i]);
    FOR(i,1,n) {
        if(m[i]<=(n>>1))cout<<a[(n>>1)+1].ss<<endl;
        else cout<<a[n>>1].ss<<endl;
    }
    return 0;
}

/**_________________________code.end__________________________**/
//***************************************************************
//***************************************************************
//***************************************************************
/****************************************************************
**                                                             **
**  *********   *********   ********    **          *********  **
**      **      **          **     **   **          **         **
**      **      **          **     **   **          **         **
**      **      *********   ********    **          *********  **
**      **      **          **     **   **          **         **
**      **      **          **     **   **          **         **
**      **      *********   ********    *********   *********  **
**                                                             **
****************************************************************/
