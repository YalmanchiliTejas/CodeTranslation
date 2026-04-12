#include <iostream>
#include <utility>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> r(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        r.at(i + 1) = r[i] + a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll sum = (r[n] - r[i + 1]) % MOD;
        ans += sum * a[i];
        ans %= MOD;
    }
    cout << ans << endl;
}
