#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ALL(x)      (x).begin(),(x).end()
#define REP(i,n)    for(int i=0;i<(n);i++)
#define REP1(i,n)   for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n)   for(int i=(n);i>=0;i--)
#define CLR(a)      memset((a),0,sizeof(a))
#define MCLR(a)     memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

const LL MOD = 998244353;
LL dp[3001][3001][3];

void solve(long long N, long long S, std::vector<long long> A){
    dp[0][0][0] = 1;

    REP(i, N) {
        REP(j, S+1) {
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j][0] %= MOD;
            if(j+A[i] <= S) {
                dp[i+1][j+A[i]][1] += ((dp[i][j][0] * (i+1)) % MOD);
                dp[i+1][j+A[i]][1] %= MOD;
                dp[i+1][j+A[i]][2] += ((dp[i][j][0] * ((i+1) * (N-i) % MOD)) % MOD);
                dp[i+1][j+A[i]][2] %= MOD;
            }

            dp[i+1][j][1] += dp[i][j][1];
            dp[i+1][j][1] %= MOD;
            if(j+A[i] <= S) {
                dp[i+1][j+A[i]][1] += dp[i][j][1];
                dp[i+1][j+A[i]][1] %= MOD;
                dp[i+1][j+A[i]][2] += ((dp[i][j][1] * (N-i)) % MOD);
                dp[i+1][j+A[i]][2] %= MOD;
            }

            dp[i+1][j][2] += dp[i][j][2];
            dp[i+1][j][2] %= MOD;
        }
    }

    cout << dp[N][S][2] << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long S;
    scanf("%lld",&S);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, S, std::move(A));
    return 0;
}

