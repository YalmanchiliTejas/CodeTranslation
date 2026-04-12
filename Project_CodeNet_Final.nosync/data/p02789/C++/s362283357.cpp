#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#include<stdio.h>
#include<functional>
#include<queue>

using ll = long long;

using namespace std;

ll mod = 1000000007;

ll n_pow(ll a, ll n) {
	if (n == 0)return 1;
	ll t = n_pow(a, n / 2);
	t *= t;
	t %= mod;
	if (n % 2 == 1)t *= a;
	return t % mod;
}

const int INF = 1001001001;
//const ll INF = 1e18;


int main() {
	int n, m;
	cin >> n >> m;
	if (n == m)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}