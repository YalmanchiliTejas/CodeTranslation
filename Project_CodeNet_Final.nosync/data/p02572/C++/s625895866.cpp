#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

int main()
{
	int n;
	cin >> n;
	vector<ll> al(n);
	vector<ll> suml(n);
	rep(i, n) {
		ll a;
		cin >> a;
		al[i] = a;
		if (i == 0)
		{
			suml[i] = a;
		}
		else
		{
			suml[i] += suml[i - 1] + a;
		}
	}
	ll ans = 0;
	rep(i, n) {
		ans += (al[i] % MOD) * ((suml[n - 1] - suml[i]) % MOD);
		ans %= MOD;
	}
	cout << ans << endl;
	system("pause");
}

