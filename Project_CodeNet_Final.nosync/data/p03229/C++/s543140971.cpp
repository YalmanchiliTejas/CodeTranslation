#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define REPr(i,n) for(int i=(n)-1;i>=0; --i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
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
int main(){
    ll N;
    SCLLD(N);

    ll ans1,ans2;
    vector<ll> A;
    VSCLLD(A,N);
    sort(A.begin(),A.end());

    ans1 = 0; ans2 = 0;
    int index = 0;
    if (N % 2 != 0){
        REP(i,N/2){
            ans1 += 2 * A[N-index-1];
            index++;
        }
        REP(j,2){
            ans1 -= A[N-index-1];
            index++;
        }
        REP(k,N - N/2 - 2){
            ans1 -= 2 * A[N-index-1];
            index++;
        }

        index = 0;
        REP(i,N/2){
            ans2 -= 2 * A[index];
            index++;
        }
        REP(j,2){
            ans2 += A[index];
            index++;
        }
        REP(k,N - N/2 - 2){
            ans2 += 2 * A[index];
            index++;
        }
    }else{
        REP(i,N/2 -1 ){
            ans1 -= 2 * A[index];
            index++;
        }
        ans1 -= A[index]; index++;
        ans1 += A[index]; index++;
        REP(j,N/2 - 1){
            ans1 += 2 * A[index];
            index++; 
        }
    }

    PRINTLLD(max(ans1,ans2));
}