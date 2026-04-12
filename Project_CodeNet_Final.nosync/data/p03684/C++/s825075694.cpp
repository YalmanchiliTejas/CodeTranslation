//# define judge
#define dalaojudge
//#include    <bits/stdc++.h>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
#define    FOR(i,a,n)       for(register int i=a;i<=n;++i)
#define    FIR(i,n,a)       for(register int i=n;i>=a;--i)
#define    VOR(i,a)         for(register int i=0,n=a.size();i<n;++i)
#define    SOR(i,a)         for(register auto i=a.begin();i!=a.end();++i)
#define    all(a)           (a).begin(),(a).end()
#define    vlb(a,n)         (lower_bound(all(a),n)-a.begin())
#define    vub(a,n)         (upper_bound(all(a),n)-a.begin())
#define    mem(a,b)         memset(a,b,sizeof(a))
#define    sz(a)            (a.size())
#define    pw(x)            (1ll<<(x))
#define    lowbit(x)        ((x)&(-x))
#define    bug              puts("\nH");
#pragma    comment(linker, "/STACK:1024000000,1024000000")
#define    IOS              ios::sync_with_stdio(false)
#define    getmid           mid=l+r>>1
#define    lch              p<<1,l,mid
#define    rch              p<<1|1,mid+1,r
#define    ll               p<<1
#define    rr               p<<1|1
#define    queue_           priority_queue
#define    pb               push_back
#define    mp               make_pair
#define    lb               lower_bound
#define    ub               upper_bound
#define    ff               first
#define    ss               second
typedef    long long        LL;
typedef    pair<double,int> db;
typedef    pair<int,int>    PII;
typedef    pair<LL,LL>      PLL;
typedef    vector<int>      VI;
typedef    vector<LL>       VLL;
typedef    vector<PII>      VPII;
typedef    vector<PLL>      VPLL;
const int           dx[]= { 0, 1, 0,-1, 0, 1,-1, 1,-1};
const int           dy[]= {-1, 0, 1, 0,-1, 1,-1,-1, 1};
const LL            LINF=0xfcfcfcfcfcfcfcfll;
const long double   pi=3.141592653589793238462643383279502881l;
const double        ee=2.718281828459;
const double        eps=0.00000001;
const int           INF=0x3f3f3f3f;
const int           MOD=1000000007;
const char          hr='\n';
const char          kb=' ';
inline LL powmod(LL x,LL n,LL mod=MOD,LL res=1) { for(; n; x=x*x%mod,n>>=1)if(n&1)res=res*x%mod; return res; }
template<typename T>inline T max(T a,T b,T c) { return max(a,max(b,c)); }
template<typename T>inline T min(T a,T b,T c) { return min(a,min(b,c)); }
template<typename T>inline T max(T a,T b,T c,T d) { return max(a,max(b,c,d)); }
template<typename T>inline T min(T a,T b,T c,T d) { return min(a,min(b,c,d)); }
inline int mul10(int n) { return (n<<3)+(n<<1); }
inline LL mul10(LL n) { return (n<<3)+(n<<1); }
inline int div10(int n,int q=0) { q=(n>>1)+(n>>2),q+=(q>>4),q+=(q>>8),q+=(q>>16),q>>=3; return q+(n-mul10(q)>9); }
inline LL div10(LL n,LL q=0) { q=(n>>1)+(n>>2),q+=(q>>4),q+=(q>>8),q+=(q>>16),q+=(q>>32),q>>=3; return q+(n-mul10(q)>9); }
static char bfi[1000000],*ci=bfi-1,*cl=bfi-1,bfo[1000000],*co=bfo-1,chr;
inline bool dig() { return (chr>='0'&&chr<='9')?1:0; }
inline char gtc() { return ci==cl&&(cl=(ci=bfi-1)+fread(bfi,1,1000000,stdin),ci==cl)?EOF:*++ci; }
inline void readbit(double &ret,double bit=0.1) { if(chr=gtc(),dig())ret+=(chr-'0')*bit,readbit(ret,bit*0.1); }
inline bool _scan(int &res,bool flag=0,bool f=0,int sum=0) { while(chr=gtc(),!(dig()||(chr=='-'?(chr=gtc(),flag=1):0))); while(dig())sum=mul10(sum)+chr-'0',f=1,chr=gtc(); return f?(res=flag?-sum:sum,1):0; }
inline bool _scan(LL &res,bool flag=0,bool f=0,LL sum=0) { while(chr=gtc(),!(dig()||(chr=='-'?(chr=gtc(),flag=1):0))); while(dig())sum=mul10(sum)+chr-'0',f=1,chr=gtc(); return f?(res=flag?-sum:sum,1):0; }
inline bool _scan(double &ret,bool flag=0,LL sum=0) { while(chr=gtc(),!(dig()||(chr=='-'?(chr=gtc(),flag=1):0))); while((dig())?1:(ret=sum,0))sum=mul10(sum)+chr-'0',chr=gtc(); if(chr=='.')readbit(ret); return ret?(ret=flag?-ret:ret):0; }
inline bool _scan(char &ch,bool f=0) { while(chr=gtc(),chr==' '||chr=='\n'); if(chr!=EOF)ch=chr,f=1; return f; }
inline bool _scan(char *p,bool f=0) { while(chr=gtc(),chr==' '||chr=='\n'); while(chr!='\n'&&chr!=EOF)*p++=chr,chr=gtc(),f=1; return (*p=0,f); }
inline void _read(int &x) { scanf("%d%*c",&x); }
inline void _read(LL &x) { scanf("%I64d%*c",&x); }
inline void _read(double &x) { scanf("%lf%*c",&x); }
inline void _read(char &ch) { scanf("%c%*c",&ch); }
inline void _read(char *p) { scanf("%s%*c",p); }
inline void _debug(int x) { printf(" %d",x); }
inline void _debug(LL x) { printf(" %I64d",x); }
inline void _debug(double x) { printf(" %.6f",x); }
inline void _debug(const char ch) { printf(" %c",ch); }
inline void _debug(const char *p) { printf(" %s",p); }
inline void _write() { fwrite(bfo,1,co-bfo+1,stdout),co=bfo-1; }
inline void ptc(char ch) { if(*++co=ch,co==bfo+999999)_write(); }
inline void _out(int x) { if(x<0)ptc('-'),x=-x; if(x>9)_out(div10(x)); ptc(x%10+'0'); }
inline void _out(LL x) { if(x<0)ptc('-'),x=-x; if(x>9)_out(div10(x)); ptc(x%10+'0'); }
inline void _out(double x,int n=6) { if(x<0)ptc('-'),x=-x; _out((LL)x),x-=(LL)x,ptc('.'); while(n--)x*=10; _out(LL(x+0.5)); }
inline void _out(db x) { _out(x.ff,x.ss); }
inline void _out(const char ch) { ptc(ch); }
inline void _out(const char *p) { while(*p)ptc(*p++); }
#ifndef dalaojudge
inline void scan() {}
template<class T,class... U>inline void scan(T head,U ...tail) { _scan(head); scan(tail...); }
inline void read() {}
template<class T,class... U>inline void read(T head,U ...tail) { _read(head); read(tail...); }
inline void debug() {}
template<class T,class... U>inline void debug(T head,U ...tail) { _debug(head); debug(tail...); }
inline void out() {}
template<class T,class... U>inline void out(T head,U ...tail) { _out(head); out(tail...); }
#else
#define read(x) _scan(x)
#define scan(x) _read(x)
#endif
/**_________________________head.end__________________________**/

const int N=100005;
int par[N];

struct node {
    int cnt;
    int x,y;
}a[N];

struct krus {
    int u,v,cost;
    friend bool operator < (krus i,krus j) {
        return i.cost<j.cost;
    }
}b[N<<2];

priority_queue<krus>q;

bool cmpx(node i,node j) {
    return i.x<j.x;
}

bool cmpy(node i,node j) {
    return i.y<j.y;
}

inline int fi(int x) {
    return par[x]?par[x]=fi(par[x]):x;
}

inline LL kruskal(int n,int m) {
    sort(b+1,b+m+1);
    int res=0,cnt=0;
    FOR(i,1,m) {
        krus e=b[i];
        int x=fi(e.u),y=fi(e.v);
        if(x!=y)par[x]=y,res+=e.cost,++cnt;
        if(cnt==n-1)break;
    }
    return res;
}

/**_______________________main().begin________________________**/
int main() {
    IOS;
#ifdef judge
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
    int n,x,y,z,num=0;
    cin>>n;
    FOR(i,1,n) {
        cin>>x>>y;
        a[i]={i,x,y};
    }
    sort(a+1,a+n+1,cmpx);
    FOR(i,1,n-1) {
        x=a[i].cnt,y=a[i+1].cnt;
        z=a[i+1].x-a[i].x;
        b[++num]={x,y,z};
        b[++num]={y,x,z};
    }
    sort(a+1,a+n+1,cmpy);
    FOR(i,1,n-1) {
        x=a[i].cnt,y=a[i+1].cnt;
        z=a[i+1].y-a[i].y;
        b[++num]={x,y,z};
        b[++num]={y,x,z};
    }
    cout<<kruskal(n,num)<<endl;
#ifndef GGG
    _write();
#endif
    return 0;
}
/**________________________main().end_________________________**/

/***************************************************************
**                                                            **
**  *********   *********   ********    **          ********* **
**      **      **          **     **   **          **        **
**      **      **          **     **   **          **        **
**      **      *********   ********    **          ********* **
**      **      **          **     **   **          **        **
**      **      **          **     **   **          **        **
**      **      *********   ********    *********   ********* **
**                                                            **
***************************************************************/
