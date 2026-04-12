#include <bits/stdc++.h>

#ifdef DEBUG
#define LOG(var, sep) (cerr << #var << " = " << (var) << (sep))

#define LOGM(msg) (cerr << (msg))

#define LOGV(vec, sep) {                                        \
    cerr << #vec << " =";                                       \
    for (const auto& v : (vec)) cerr << " " << v;               \
    cerr << (sep); }

#define LOGA(arr, N, sep) {                                     \
        cerr << #arr << " =";                                   \
        for (int i = 0; i < N; ++i) cerr << " " << (arr)[i];    \
        cerr << (sep); }

#define LOGA2(arr, N, M, sep) {                                 \
        cerr << #arr << " =\n";                                 \
        for (int i = 0; i < N; ++i) {                           \
            for (int j = 0; j < M; ++j)                         \
                cerr << (arr)[i][j] << " ";                     \
            cerr << endl;                                       \
        } cerr << (sep); }
#else
#define LOG(var, sep)
#define LOGM(msg)
#define LOGV(vec, sep)
#define LOGA(arr, N, sep)
#define LOGA2(arr, N, M, sep)
#endif

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll mod(ll x)
{
    return (((x % MOD) + MOD) % MOD);
}

ll mod_pow(ll a, ll n)
{
    ll res = 1, base = a;

    while (n)
    {
        if (n & 1)
            res = (res * base) % MOD;

        base = (base * base) % MOD;
        n >>= 1;
    }

    return res;
}

ll solve(int, const vector<ll>& xs)
{
    ll sum = accumulate(xs.begin(), xs.end(), 0LL);
    sum = mod(sum);
    ll ans = mod(sum * sum);

    for (auto x : xs)
        ans = mod(ans - x*x);

    ans = mod(ans * mod_pow(2, MOD - 2));

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, xs);

    cout << ans << '\n';

    return 0;
}
