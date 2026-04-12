#include <bits/stdc++.h>

#define taskname ""
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> cd;
typedef vector <cd> vcd;
typedef vector <int> vi;

template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 3e3 + 10;

int n;
ll a[maxN];

ll dp[maxN][maxN][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for1(i, n)
    {
        cin >> a[i];
        dp[i][i][0] = a[i];
        dp[i][i][1] = -a[i];
    }
    fore(d, 2, n)
    {
        for1(i, n - d + 1)
        {
            int j = i + d - 1;
            dp[i][j][0] = max(a[i] + dp[i + 1][j][1], a[j] + dp[i][j - 1][1]);
            dp[i][j][1] = min(dp[i + 1][j][0] - a[i], dp[i][j - 1][0] - a[j]);
        }
    }
    cout << dp[1][n][0];
    return 0;
}
