#include<bits/stdc++.h> 
#define REP(i, b) for(int i = 0; i < (b); i++)
#define REPS(i, b) for(int i = 1; i <= (b); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vb = vector<bool>;
const int INF = 1e9;
const int MOD = 1e9+7;

string N;
int K;
int dp[110][2][110];

ll solve(int k = 0, bool smaller = false, int sum = 0)
{
    if(dp[k][smaller][sum] != -1) return dp[k][smaller][sum];
    if(sum > K) return 0;
    if(k == N.length()) return sum == K;
    int x = N[k] - '0';
    int r = (smaller) ? 9 : x;
    int ret = 0;
    for(int i = 0; i <= r; i++)
    {
        ret += solve(k+1, smaller || i < r, sum + min(1, i));
    }
    return dp[k][smaller][sum] = ret;
}

signed main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    cout << solve() << endl;
}