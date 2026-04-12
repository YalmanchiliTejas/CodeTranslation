#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<double>;
using vvd = vector<vd>;

#define out(a) cout << a << endl
#define out1(a) cout << a
#define in(a) cin >> a
#define in2(a, b) cin >> a >> b
#define in3(a, b, c) cin >> a >> b >> c
#define rep(i, N) for (ll i = 0; i < (ll)N; i++)
#define rep1(i, N) for (ll i = 1; i <= (ll)N; i++)
#define repi(i, j, N) for (ll j = (ll)i + 1; j < (ll)N; j++)
#define all(v) v.begin(), v.end()

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

constexpr int inf = 1e9;
constexpr ll linf = 1e18;
constexpr ll mod = 1e9 + 7;

void solve();

int main()
{
    solve();
}

void solve()
{
    int a, b, c, x, y;
    in3(a, b, c);
    in2(x, y);
    int sum = 0;
    if (a + b < 2 * c)
    {
        sum = a * x + b * y;
    }
    else
    {
        if (x > y)
        {
            sum = 2 * c * y;
            if (a < 2 * c)
            {
                sum += a * (x - y);
            }
            else
            {
                sum += 2 * c * (x - y);
            }
        }
        else
        {
            sum = 2 * c * x;
            if (b < 2 * c)
            {
                sum += b * (y - x);
            }
            else
            {
                sum += 2 * c * (y - x);
            }
        }
    }
    out(sum);
}