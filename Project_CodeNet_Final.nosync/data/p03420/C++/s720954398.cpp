#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = (int)1e9 + 7;
const int MAX_N = (int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

void solve()
{
    ll n, k; cin >> n >> k;
    ll ans = 0;
    if(k == 0)
    {
        cout << n * n << endl;
        return;
    }
    for(ll b = k + 1; b <= n; b++)
    {
        ll cnt = max(0LL, b - k);
        ans += n / b * cnt;
        ans += max(0LL, n % b - k + 1);
    }
    cout << ans << endl;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}