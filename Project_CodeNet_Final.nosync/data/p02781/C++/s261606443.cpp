#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

int to_int(const char c){
    if('0' <= c && c <= '9') return (c-'0');
    else return -1;
}               

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    string S;cin >> S;int N = S.size();
    int K;cin >> K;
    int dp[N+10][K+10][2] = {};
    dp[0][0][0] = 1;
    REP(i,N)REP(j,K+1)REP(k,2){
        int nd = to_int(S[i]);
        REP(d,10){
            int ni = i+1,nj = j,nk = k;
            if(d != 0) nj++;
            if(k == 0){
                if(d > nd) continue;
                if(d < nd) nk= 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    cout << dp[N][K][1] + dp[N][K][0] << endl;
}