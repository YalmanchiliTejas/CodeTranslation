#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

long long pow(const long long &v, const long long &n, const long long &mod)
{
    long long ret = 1;
    long long num = n;
    long long now = v;
    
    while (num > 0)
    {
        if (num & 1)
        {
            ret = ret * now % mod;
        }
        now = now * now % mod;
        num = num >> 1;
    }
    
    return ret;
}

long long calc(const long long &n, const long long &k, const long long &mod)
{
    long long ret;
    vector<ll> fac = vector<long long>(n + 1, 1);
    vector<ll> inv = vector<long long>(n + 1, 1);
    
    for (int i = 1; i <= n; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = pow(fac[i], mod - 2, mod);
    }
    
    ret = fac[n] * inv[k] % mod * inv[n - k] % mod;
    
    return ret;
}

const int mod = 1e9 + 7;

int main() {
    

    
    ll n, m, k;
    cin >> n >> m >> k;
    
    ll ret = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        ret += ((((n - i) * m) % mod) * m % mod) * i % mod;
        ret %= mod;
    }
    
    
    for (int i = 1; i <= m - 1; ++i)
    {
        ret += ((((m - i) * n) % mod) * n % mod) * i % mod;
        ret %= mod;
    }
    
    ll comb = calc(n * m - 2ll, k - 2, mod);
    
    cout << (ret * comb) % mod << endl;
    
    return 0;
}