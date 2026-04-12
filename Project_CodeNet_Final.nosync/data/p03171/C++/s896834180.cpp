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
constexpr int INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

int N;
ll A[3100];
ll dp[3100][3100];
bool used[3100][3100];

ll solve(int L,int R){
    if(L > R) return 0;
    if(used[L][R]) return dp[L][R];
    used[L][R] = 1;
    int diff = (N - R - L + 1) % 2;
    ll ans = 0;
    if(diff){
        ans = INFF;
        ans = min(ans,solve(L+1,R) - A[L]);
        ans = min(ans,solve(L,R-1) - A[R]);
    }
    else{
        ans = -INFF;
        ans = max(ans,solve(L+1,R) + A[L]);
        ans = max(ans,solve(L,R-1) + A[R]);
    }
    return dp[L][R] = ans;
}

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    cin >> N;
    REP(i,N) cin >> A[i];
    cout << solve(0,N-1) << endl;
}