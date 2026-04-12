#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long int
const int mod = 1e9 + 7;
void testcase()
{
    ll n;
    cin >> n;
    ll ar[n + 1];
    // ll t[n + 1] = {0};
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> ar[i];
        // t[i] = (ar[i] % mod + t[i - 1] % mod) % mod;
        sum = (sum % mod + ar[i] % mod) % mod;
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        // cout << t[n - i] << " ";
        sum = (sum % mod - ar[i] % mod) % mod;
        if(sum < 0){
            sum += mod;
        }
        ans = (ans % mod + (ar[i] % mod * sum % mod) % mod) % mod;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testcase();
    return 0;
}
