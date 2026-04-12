#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define REPr(i,n) for(int i=(n)-1;i>=0; --i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define rFORq(i, m , n) for(int i = (n);i >=(m);--i)
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define SCLLD(n) scanf("%lld",&n)
#define SCLLD2(m,n) scanf("%lld%lld",&m,&n)
#define SCLLD3(m,n,k) scanf("%lld%lld%lld",&m,&n,&k)
#define PB push_back
#define MP make_pair
#define ARSCD(A,N) REP(i,N){SCD(A[i]);}
#define ARSCD1(A,N) FORq(i,1,N){SCD(A[i]);}
#define VSCD(v,N) REP(i,N){int x; SCD(x); v.PB(x);}
#define VSCLLD(v,N) REP(i,N){long long x; SCLLD(x); v.PB(x);}
#define PRINTD(n) printf("%d\n",n)
#define PRINTLLD(n) printf("%lld\n",n)
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x,S) (S.count(x) != 0)
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector < VI > VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
////////////////////////////////////////////////////////////////////
ll X[52];
ll P[52];

ll F(long long x, long long L){
    if ((L==0) and (x==1)) return 1;
    if (x == 1) return 0;
    else if ((1 < x) and (x <= 1+X[L-1])) return F(x-1,L-1);
    else if (x == 2 + X[L-1]) return P[L-1] + 1;
    else if ((2 + X[L-1] < x) and (x <= 2 + 2*X[L-1])) return 1 + P[L-1] + F(x-2-X[L-1],L-1);
    else if (x== 3 + 2*X[L-1]) return 2 * P[L-1]+ 1;
    return 0;
}

int main(){
    ll N; SCLLD(N);
    ll x; SCLLD(x);

    X[0] = 1;
    P[0] = 1;
    FORq(i,1,50){
        P[i] = 2 * P[i-1] + 1;
        X[i] = 2 * X[i-1] + 3;
    }

    PRINTLLD(F(x,N));
}