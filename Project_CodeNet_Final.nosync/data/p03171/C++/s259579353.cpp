	#include <iostream>
	#include <stdio.h>
	#include <vector>
	#include <string>
	#include <set>
	#include <queue>
	#include <cmath>
	#include <map>
	#include <algorithm>
	#include <stack>
	#include <cstring>
	 
	#define ll long long
	#define MP make_pair
	#define PB push_back
	#define P push
	#define f first
	#define se second
	#define S size()
	#define B begin()
	#define E end()
	#define rB rbegin()
	#define rE rend()
	#define PI acos(-1)
	#define speed ios::sync_with_stdio(0); cin.tie(0);
	 
	 
	const int N = 1e5 + 100;
	const int M = 1e6 + 100;
	const ll oo = 2e18;
	 
	ll n, m, k, t, q, h, a, b, d, c, e, w, x, y, z;
	using namespace std;

	int ar[3003];
	ll dp[3003][3003][2];

	ll calc(int l, int r, bool f) {
		if(l == r) {
			return ar[l] * pow(-1, f);
		}

		ll &ret = dp[l][r][f];

		if(ret != -1) return ret;

		if(f) 
			ret = min(-ar[r] + calc(l, r - 1, !f), -ar[l] + calc(l + 1, r, !f));
		
		else 
			ret = max(ar[r] + calc(l, r - 1, !f), ar[l] + calc(l + 1, r, !f));


		return ret;
	}
	 
	int main() {
		

		cin >> n;

		memset(dp, -1, sizeof dp);

		for(int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		cout << calc(0, n - 1, 0);


	    return 0;
	}

