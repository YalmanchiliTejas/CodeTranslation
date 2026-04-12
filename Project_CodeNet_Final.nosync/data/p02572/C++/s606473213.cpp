#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    ll sum = 0;
    rep(0, i, N)
    {
        cin >> a.at(i);
        sum += a.at(i);
    }

    vector<ll> subsum(N);
    subsum.at(0) = sum - a.at(0);
    rep(1, i, N)
    {
        subsum.at(i) = subsum.at(i - 1) - a.at(i);
    }

    ll ans = 0;
    rep(0, i, N)
    {
        ans += a.at(i) * (subsum.at(i) % MOD);
        ans %= MOD;
    }

    cout << ans << endl;
}