#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

int n;
int data[3001];
int dp[3001][3001];

int mmnmm(int st, int en, bool turn)
{
    if (dp[st][en] != INF) return dp[st][en];
    if (st == en) {
      int tmp = 1; 
      if (!turn) tmp = -1;
      return dp[st][en] = data[st] * tmp;
    }
    if (turn) {
        return dp[st][en] = max(data[st] + mmnmm(st+1, en, !turn), 
            data[en] + mmnmm(st, en-1, !turn));
    } else {
        return dp[st][en] = min(-data[st] + mmnmm(st+1, en, !turn), 
            -data[en] + mmnmm(st, en-1, !turn));
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    rep(i, n) {
        cin >> data[i];
    }

    rep(i, n) {
        rep(j, n) {
            dp[i][j] = INF;
        }
    }

    cout << mmnmm(0, n-1, true) << endl;

    return 0;
}
