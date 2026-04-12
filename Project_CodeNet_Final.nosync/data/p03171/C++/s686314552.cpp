#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#define MOD(x) (x + 1000000007) % (1000000007)

using namespace std;

template <class t>
using vec = vector<t>;
using ll = long long;

const int MAX = numeric_limits<int>::max();

template <class t>
ostream &operator<<(ostream &out, vec<t> &v)
{
    for (auto &e : v)
        out << e << " ";
    out << "\n";
    return out;
}

template <class t>
istream &operator>>(istream &in, vec<t> &v)
{
    for (auto &e : v)
        in >> e;
    return in;
}

vec<ll> a;
vec<vec<pair<ll, ll>>> dp;
pair<ll, ll> DEFAULT = {0, 0};
int n;

pair<ll, ll> find(int l, int r, bool move)
{
    if (l == r)
        return (move ? pair<ll, ll>(a[l], 0) : pair<ll, ll>(0, a[l]));
    if (dp[l][r] != DEFAULT)
        return dp[l][r];
    auto lt = find(l + 1, r, !move), rt = find(l, r - 1, !move);
    if (!move)
    {
        lt = {lt.second, lt.first};
        rt = {rt.second, rt.first};
    }
    if (lt.first + a[l] > rt.first + a[r])
        dp[l][r] = {lt.first + a[l], lt.second};
    else
        dp[l][r] = {rt.first + a[r], rt.second};
    if (!move)
        dp[l][r] = {dp[l][r].second, dp[l][r].first};
    return dp[l][r];
}

int main()
{
    cin >> n;
    a = vec<ll>(n);
    cin >> a;
    dp = vec<vec<pair<ll, ll>>>(n, vec<pair<ll, ll>>(n, {0, 0}));
    auto xy = find(0, n - 1, true);
    cout << (xy.first - xy.second);
    return 0;
}