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

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    ll ans = 0;
    ll sum = 0;
    ll sums = 0;

    ans = 0;

    for (int i = 0; i < n; i++)
    {
        sums += a[i];
        sums %= mod;
    }

    ans += (sums* sums)%mod;

    for (int i = 0; i < n; i++)
    {
        ans -= (a[i] * a[i]) % mod;

        if (ans < 0)
        {
            ans += mod;
        }

        ans %= mod;
    }



    ans= ans*modinv(2, mod);
    ans %= mod;

    cout << ans << endl;
}

/*
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
*/