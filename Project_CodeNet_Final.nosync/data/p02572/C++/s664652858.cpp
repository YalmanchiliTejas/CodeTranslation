#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline void chmax(T1 &a, const T2 &b)
{
    if (a < b)
    {
        a = b;
    }
}
template <class T1, class T2>
inline void chmin(T1 &a, const T2 &b)
{
    if (a > b)
    {
        a = b;
    }
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll mod = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vl A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    ll ans = 0;
    ll sum = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        ans += sum * A[i];
        ans %= mod;
        sum += A[i];
        sum %= mod;
    }
    cout << ans << endl;
}