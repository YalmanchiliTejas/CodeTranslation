#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>

using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)

#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define op(i) cout << (i) << endl;
#define F first
#define S second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll mod = 1e9 + 7;
const int infi = 2147483647;
const ll infl = 1e17;

ll powmod(ll x, ll y, ll mod)
{
    map<ll, ll> Z;
    Z[0] = 1;
    Z[1] = x;
    ll nowy = 1;
    ll nowx = x;
    while (nowy * 2 <= y)
    {
        nowy *= 2;
        nowx = nowx * nowx % mod;
        Z[nowy] = nowx;
    }
    ll nowz = nowy / 2;
    while (nowy < y)
    {
        if (nowz + nowy <= y)
        {
            nowy += nowz;
            nowx = (nowx * Z[nowz]) % mod;
        }
        nowz /= 2;
    }
    return nowx;
}

int main()
{
    ll n,m,k;
    cin >> n >> m >> k;
    ll L = n * m;
    vector<ll> kaijo(L + 1, 0);
    kaijo[0] = 1;
    repf(i, 1, L + 1)
        kaijo[i] = (kaijo[i - 1] * i) % mod;
    vector<ll> gyaku(L + 1, 0);
    gyaku[L] = powmod(kaijo[L], mod - 2, mod);
    rep(i, L)
        gyaku[L - 1 - i] = gyaku[L - i] * (L - i) % mod;
    ll ans = 0;
    repf(i,1,n+1){
        ll res = i * (n - i) % mod;
        res = (res * m % mod) * m % mod;
        res = (res * kaijo[n * m - 2]) % mod;
        res = (res * gyaku[k - 2]) % mod;
        res = (res * gyaku[n * m - k]) % mod;
        ans = (ans + res) % mod;
    }

    repf(i, 1, m + 1)
    {
        ll res = i * (m - i) % mod;
        res = (res * n % mod) * n % mod;
        res = (res * kaijo[n * m - 2]) % mod;
        res = (res * gyaku[k - 2]) % mod;
        res = (res * gyaku[n * m - k]) % mod;
        ans = (ans + res) % mod;
    }
    cout << ans << endl;
}
