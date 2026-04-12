#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string.h>
#include <map>
#include <stack>
#include <iomanip>
#include <chrono>
#include <random>
#include <math.h>
#include <time.h>
#include <bitset>
#include <assert.h>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) x.begin(),x.end() 
#define PII pair <ll,ll>
#define N 100005
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;

ll func(ll n)
{
	return (n * (n + 1)) / 2;
}
ll power(ll a,ll b, ll c)
{
    ll res = 1;
    while(b != 0)
    {
        if(b & 1)
            res = (res * a) % c;
        a = (a * a) % c;
        b /= 2;
    }
    return res;
}
int main()
{
	ll n, m, k, ans = 0, xval, yval;
	cin >> n >> m >> k;
	ll fact[2 * N];
	fact[0] = 1;
	for (int i = 1; i < 2 * N; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	ll nmck = fact[n * m - 2] * ((power(fact[(n * m - 2) - (k - 2)], MOD - 2, MOD) * power(fact[k - 2], MOD - 2, MOD)) % MOD);
	nmck %= MOD;
	cerr << nmck;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			xval = func(n - i) * m + func(i - 1) * m;
			yval = func(m - j) * n + func(j - 1) * n;
			xval %= MOD;
			yval %= MOD;
			// cerr << i << " " << j << " " << xval << " " << yval << "\n";
			ans = (ans + nmck * (xval + yval)) % MOD;
		}
	}
	cout << (ans * power(2, MOD - 2, MOD)) % MOD;
}
