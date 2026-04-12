#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

const ll modint = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum -= a[i];
        ans += a[i] * (sum % modint);
        ans %= modint;
    }
    cout << ans << endl;
    return 0;
}