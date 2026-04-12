#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <numeric>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007

int main()
{
    int n;cin >> n;
    vector<ll> a(n);
    vector<ll> b(n-1);
    rep(i,n) {
        cin >> a[i];
    }

    ll ans = 0;
    ll sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += a[i];  
    }


    int i = 1;
    for(int j = 0; j < n - 1; j++) {
        b[j] = sum;
        sum -= a[i++];
    }

    for(int i = 0; i < n - 1; i++) {
        ans += (b[i]%mod)*(a[i]%mod);
        ans %= mod;
    }



    cout << ans << endl;

}