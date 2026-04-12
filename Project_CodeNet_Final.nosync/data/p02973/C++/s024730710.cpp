#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <iomanip>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

const int INF = 100000000;
const ll MOD = 1000000007;

ll pow_mod(ll x, ll y, ll mod)
{
    if (y == 0)
        return 1;
    if (y % 2)
    {
        return (x * pow_mod(x, y - 1, mod)) % mod;
    }
    else
    {
        return pow_mod(x * x, y / 2, mod);
    }
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    //問題文中の添え字が0-indexか1-indexか確認!
    ll n;
    std::cin >> n;
    std::vector<ll> a(n), seq;
    rep(i, 0, n)
    {
        std::cin >> a[i];
    }
    seq.push_back(a[0]);
    rep(i, 1, n)
    {
        if (a[i] <= seq[0])
        {
            seq.insert(seq.begin(), a[i]);
        }
        else
        {
            auto itr = std::lower_bound(all(seq), a[i]);
            itr--;
            *itr = a[i];
        }
    }
    std::cout << seq.size();
    return 0;
}