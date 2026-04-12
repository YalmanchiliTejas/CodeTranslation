#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
const int MAX_N = 3100;

int N;
vector<ll> a;

ll dp[MAX_N][MAX_N];

ll Solve(int i, int j)
{
    if (dp[i][j] != -1000000000000LL) return dp[i][j];

    if (i + j >= N) return 0;

    if ((i + j) % 2 == 0)
    {
        return dp[i][j] = max(a[i] + Solve(i + 1, j), a[N - (j + 1)] + Solve(i, j + 1));
    }
    else
    {
        return dp[i][j] = min(- a[i] + Solve(i + 1, j), - a[N - (j + 1)] + Solve(i, j + 1));
    }
}

void _main()
{
    cin >> N;
    a.resize(N);
    rep(i, 0, N) cin >> a[i];

    rep(i, 0, MAX_N) rep(j, 0, MAX_N) dp[i][j] = -1000000000000LL;

    cout << Solve(0, 0) << endl;
}
