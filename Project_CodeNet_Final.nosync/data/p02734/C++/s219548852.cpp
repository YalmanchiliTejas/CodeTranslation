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
const int maxS = 3e3 + 10;
const ll mod = 998244353;

int n, s, a[maxN];
ll dp[maxS], ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for1(i, n)
    {
        cin >> a[i];
    }
    for1(i, n)
    {
        dp[0] = i;
        if (s >= a[i])
        {
            ans += dp[s - a[i]] * (n - i + 1) % mod;
            ans %= mod;
        }
        for (int j = s; j >= a[i]; --j)
        {
            dp[j] += dp[j - a[i]];
            dp[j] %= mod;
        }
    }
    cout << ans;
    return 0;
}
