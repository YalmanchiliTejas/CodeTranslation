#include <bits/stdc++.h>

#if ((_WIN32 || __WIN32__) && __cplusplus < 201103L)
#define lld I64d
#else
#define lld lld
#endif

//{{{
using namespace std;
typedef long long LL;
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define clr(a, b) memset(a, b, sizeof(a))
// clang-format off
#define debug(args...) {vector<string> _v = split(#args, ','); err(_v.begin(), args); cerr<<endl;}
vector<string> split(const string& s, char c) {vector<string> v; stringstream ss(s); string x; while
(getline(ss, x, c)) v.push_back(x); return v;} void err(vector<string>::iterator) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args)
{cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; err(++it, args...);}
// clang-format on
//}}}

const int N = 3000 + 10;
int n;
LL a[N], s[N];
LL dp[2][N][N];

LL calc(int l, int r) { return s[r] - s[l - 1]; }

LL dfs(int l, int r, int fg)
{
    if (dp[fg][l][r] != -1) return dp[fg][l][r];

    if (l > r) return 0;
    if (l == r) return dp[fg][l][r] = a[l];

    LL ret = 0;
    LL v1 = dfs(l + 1, r, fg ^ 1);
    LL v2 = dfs(l, r - 1, fg ^ 1);

    ret = max(calc(l + 1, r) - v1 + a[l], calc(l, r - 1) - v2 + a[r]);
    // debug(l, r, v1, v2, fg, ret);

    return dp[fg][l][r] = ret;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
// freopen("out", "w", stdout);
#endif

    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        s[0] = 0;
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

        clr(dp, -1);
        LL ans = dfs(1, n, 0);

        cout << ans * 2 - s[n] << endl;
    }

    return 0;
}
