/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
LL fac[SIZE],inv[SIZE];
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
LL C(int x,int y){
    if(y<0||y>x)return 0;
    return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
void build(){
    assert(MOD>=SIZE);
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
PLL solve(int AA[],int N){
    int BB[100];
    int mi=1e9,ma=0;
    REP(i,N){
        mi=min(mi,AA[i]);
        ma=max(ma,AA[i]);
    }
    if(mi==ma){
        return MP(mypow(2,ma-1),mypow(2,N-1)-1);
    }
    REP(i,N){
        BB[i]=AA[i]-mi;
    }
    PLL res={1LL,1LL};
    LL minus=1;
    for(int i=0,j;i<N;i=j){
        if(i)res.S=res.S*2%MOD;
        if(BB[i]==0){
            j=i+1;
            continue;
        }
        for(j=i+1;j<N&&BB[j];j++);
        PLL ret=solve(BB+i,j-i);
        res.S=res.S*(2*ret.F+ret.S)%MOD;
        minus=minus*ret.F*2%MOD;
        res.F=res.F*ret.F*2%MOD;
    }
    ADD(res.S,-minus);
    res.F=res.F*mypow(2,mi-1)%MOD;
    return res;
}
int AA[SIZE];
int main(){
    build();
    int N; R(N);
    FOR(i,1,N)R(AA[i]);
    LL uni=0;
    FOR(i,1,N){
        if(AA[i]==1){
            AA[i]=0;
            uni++;
        }
    }
    FOR(i,1,N){
        if(AA[i]>max(AA[i-1],AA[i+1])){
            uni+=AA[i]-max(AA[i-1],AA[i+1]);
            AA[i]=max(AA[i-1],AA[i+1]);
        }
    }
    LL an=mypow(2,uni);
    for(int i=1,j;i<=N;i=j){
        if(AA[i]==0){
            j=i+1;
            continue;
        }
        for(j=i+1;j<=N&&AA[j];j++);
        PLL res=solve(AA+i,j-i);
        an=an*2LL*(res.F+res.S)%MOD;
    }
    W(an);
    return 0;
}
