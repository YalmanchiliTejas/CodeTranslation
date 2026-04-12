#pragma region template 1.2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a) \
    REP(i, (a).size()) { cout << (a[i]) << (i == (a).size() - 1 ? "\n" : " "); }
#define FOUT(x) cout << fixed << setprecision(15) << (x) << endl;
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#pragma endregion template

ll N;
vi A;
map<ii, ll> dp;

ll f(ll i, ll k)
{
    ii p = ii(i, k);
    if (dp.find(p) != dp.end())
    {
        return dp[p];
    }
    if (k == 0)
    {
        return 0;
    }
    if (2 * k - 1 == i)
    {
        dp[p] = f(i - 2, k - 1) + A[i - 1];
        return dp[p];
    }
    dp[p] = max(f(i - 1, k), f(i - 2, k - 1) + A[i - 1]);
    return dp[p];
}

int main()
{

    cin >> N;
    A = vi(N);
    REP(i, N)
    {
        cin >> A[i];
    }

    ll ans = f(N, N / 2);
    OUT(ans);
}