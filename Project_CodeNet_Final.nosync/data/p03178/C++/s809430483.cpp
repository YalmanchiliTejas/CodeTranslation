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

const int maxN = 1e4 + 10;
const int maxD = 1e2 + 10;
const ll mod = 1e9 + 7;

int n, d;
char a[maxN];
ll dp[maxN][maxD][2];

ll f(int i, int x, bool sm)
{
    if (i > n)
    {
        return x == 0;
    }
    ll &res = dp[i][x][sm];
    if (res != -1)
    {
        return res;
    }
    res = 0;
    if (sm)
    {
        for0(j, 10)
        {
            res += f(i + 1, (x + j) % d, 1);
        }
    }
    else
    {
        for0(j, a[i])
        {
            res += f(i + 1, (x + j) % d, 1);
        }
        res += f(i + 1, (x + a[i]) % d, 0);
    }
    return res %= mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> (a + 1) >> d;
    n = strlen(a + 1);
    for1(i, n)
    {
        a[i] -= '0';
    }
    memset(dp, 0xff, sizeof(dp));
    cout << (f(1, 0, 0) - 1 + mod) % mod;
    return 0;
}
