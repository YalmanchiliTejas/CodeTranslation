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
#define PB emplace_back
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
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
int AA[SIZE];
int dp[2048][2048],base;
int ma_row[2048];
void maa(int &x,int v){if(x<v)x=v;}
void dfs0(int id,VI d1,VI d2){
    if(id==6){
        int v=0;
        if(d1[0]==d1[1]&&d1[1]==d1[2])v=1;
        maa(ma_row[d2[0]],v);
        maa(ma_row[d2[1]],v);
        dp[d2[0]][d2[1]]=v;
        dp[d2[1]][d2[0]]=v;
        return;
    }
    if(SZ(d1)<3){
        d1.PB(AA[id]);
        dfs0(id+1,d1,d2);
        d1.pop_back();
    }
    if(SZ(d2)<2){
        d2.PB(AA[id]);
        dfs0(id+1,d1,d2);
    }
}
void solve() {
    int N;
    R(N);
    FOR(i,1,N)FOR(j,1,N)dp[i][j]=-MOD;
    FOR(i,1,N)ma_row[i]=-MOD;
    FOR(i,1,3*N)R(AA[i]);
    if(N==1){
        W((AA[1]==AA[2]&&AA[2]==AA[3])?1:0);
        return;
    }
    VI d1,d2;
    dfs0(1,d1,d2);
    FOR(i,2,N-1){
        int x,y,z;
        tie(x,y,z)=make_tuple(AA[i*3],AA[i*3+1],AA[i*3+2]);
        int tmp[3]={x,y,z};
        vector<pair<PII,int>>ud;
        if(x==y&&y==z){
            base++;
        } else {
            if(x==y){
                FOR(ii,1,N){
                    if(dp[x][ii]==-MOD)continue;
                    ud.PB(MP(MP(ii,z),dp[x][ii]+1));
                }
            }
            if(x==z){
                FOR(ii,1,N){
                    if(dp[x][ii]==-MOD)continue;
                    ud.PB(MP(MP(ii,y),dp[x][ii]+1));
                }
            }
            if(y==z){
                FOR(ii,1,N){
                    if(dp[y][ii]==-MOD)continue;
                    ud.PB(MP(MP(ii,x),dp[y][ii]+1));
                }
            }
            if(dp[x][x]!=-MOD){
                ud.PB(MP(MP(y,z),dp[x][x]+1));
            }
            if(dp[y][y]!=-MOD){
                ud.PB(MP(MP(x,z),dp[y][y]+1));
            }
            if(dp[z][z]!=-MOD){
                ud.PB(MP(MP(x,y),dp[z][z]+1));
            }
            int my_ma=-MOD;
            FOR(k,1,N)maa(my_ma,ma_row[k]);
            ud.PB(MP(MP(x,y),my_ma));
            ud.PB(MP(MP(x,z),my_ma));
            ud.PB(MP(MP(y,z),my_ma));
            for(int v:tmp){
                FOR(k,1,N){
                    if(ma_row[k]!=-MOD){
                        ud.PB(MP(MP(v,k),ma_row[k]));
                    }
                }
            }
        }
        for(auto tt:ud){
            PII &ste=tt.F;
            maa(dp[ste.F][ste.S],tt.S);
            maa(dp[ste.S][ste.F],tt.S);
            maa(ma_row[ste.F],tt.S);
            maa(ma_row[ste.S],tt.S);
        }
    }
    int an=0;
    FOR(i,1,N)FOR(j,1,N){
        if(dp[i][j]==-MOD)continue;
        if(i==j&&AA[N*3]==i)an=max(an,dp[i][j]+base+1);
        else an=max(an,dp[i][j]+base);
    }
    W(an);
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
