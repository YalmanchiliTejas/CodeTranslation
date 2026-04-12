/*{{{*/
#include <bits/stdc++.h>
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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
int s[SIZE],t[SIZE];
ULL u[SIZE],v[SIZE];
int get_bit(ULL x,int c){return (x>>c)&1;}
ULL ans[501][501];
char d[501][501];
int main(){
    int N;
    R(N);
    FOR(i,1,N)R(s[i]);
    FOR(i,1,N)R(t[i]);
    FOR(i,1,N)scanf("%llu",&u[i]);
    FOR(i,1,N)scanf("%llu",&v[i]);
    REP(bb,64){
        memset(d,(char)3,sizeof(d));
        VI rr,cc;
        VI row_now(N+1),col_now(N+1),row_need(N+1),col_need(N+1);
        FOR(i,1,N){
            int me=get_bit(u[i],bb);
            if(!s[i]){ // and
                if(me){
                    FOR(j,1,N)d[i][j]&=2,col_now[j]|=2;
                }
                else {
                    row_need[i]|=1;
                    rr.PB(i);
                }
            }
            else{ // or
                if(!me){
                    FOR(j,1,N)d[i][j]&=1,col_now[j]|=1;
                }
                else {
                    row_need[i] |= 2;
                    rr.PB(i);
                }
            }
        }
        FOR(j,1,N){
            int me=get_bit(v[j],bb);
            if(!t[j]){
                if(me){
                    FOR(i,1,N)d[i][j]&=2,row_now[i]|=2;
                }
                else {
                    cc.PB(j);
                    col_need[j] |= 1;
                }
            }
            else{
                if(!me){
                    FOR(i,1,N)d[i][j]&=1,row_now[i]|=1;
                }
                else {
                    cc.PB(j);
                    col_need[j] |= 2;
                }
            }
        }
        if(SZ(cc)==0||SZ(rr)==0){
        }
        else if(SZ(rr)==1&&SZ(cc)==1){
            if(row_need[rr[0]]&&(row_need[rr[0]]&row_now[rr[0]])==0){
                d[rr[0]][cc[0]]=row_need[rr[0]];
            }
            else if(col_need[cc[0]]&&(col_need[cc[0]]&col_now[cc[0]])==0){
                d[rr[0]][cc[0]]=col_need[cc[0]];
            }
            else d[rr[0]][cc[0]]=2;
        }
        else if(SZ(rr)==1){
            REP(j,SZ(cc)){
                if(col_need[cc[j]]&&(col_need[cc[j]]&col_now[cc[j]])==0){
                    d[rr[0]][cc[j]]=col_need[cc[j]];
                }
                else{
                    d[rr[0]][cc[j]]=row_need[rr[0]];
                }
            }
        }
        else if(SZ(cc)==1){
            REP(i,SZ(rr)){
                if(row_need[rr[i]]&&(row_need[rr[i]]&row_now[rr[i]])==0){
                    d[rr[i]][cc[0]]=row_need[rr[i]];
                }
                else{
                    d[rr[i]][cc[0]]=col_need[cc[0]];
                }
            }
        }
        else{
            int mii=min(SZ(rr),SZ(cc));
            REP(i,SZ(rr))REP(j,SZ(cc)){
                d[rr[i]][cc[j]]=(i%mii==j%mii)?2:1;
            }
        }
        FOR(i,1,N)FOR(j,1,N)if(d[i][j]==2)ans[i][j]|=(ULL)1<<bb;
    }
    FOR(i,1,N){
        if(!s[i]){ //and
            ULL now=ans[i][1];
            FOR(j,1,N){
                now&=ans[i][j];
            }
            if(now!=u[i]){
                W(-1);
                return 0;
            }
        }
        else{ // or
            ULL now=ans[i][1];
            FOR(j,1,N){
                now|=ans[i][j];
            }
            if(now!=u[i]){
                W(-1);
                return 0;
            }
        }
    }
    FOR(j,1,N){
        if(!t[j]){ //and
            ULL now=ans[1][j];
            FOR(i,1,N){
                now&=ans[i][j];
            }
            if(now!=v[j]){
                W(-1);
                return 0;
            }
        }
        else{ // or
            ULL now=ans[1][j];
            FOR(i,1,N){
                now|=ans[i][j];
            }
            if(now!=v[j]){
                W(-1);
                return 0;
            }
        }
    }
    FOR(i,1,N){
        FOR(j,1,N){
            printf("%llu%c",ans[i][j]," \n"[j==N]);
        }
    }
    return 0;
}
