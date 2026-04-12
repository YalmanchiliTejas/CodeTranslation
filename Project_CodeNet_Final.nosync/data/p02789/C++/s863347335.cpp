#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:512000000")
#include<utility>
#include<iostream>
#include<fstream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<functional>
#include<random>
#include<climits>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<cassert>
#include<ccomplex>

//4Head

#define all(x) x.begin(), x.end()
#define mp make_pair
#define X first
#define Y second

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 gen(time(NULL));

ll const mod = 1e9 + 7;

namespace {
	ll mul(ll a, ll b) {
		ll val = a * b - (ll)((ld)a * b / mod) * mod;
		if (val < 0) val += mod;
		if (val >= mod) val -= mod;
		return val;
	}

	ll poww(ll a, ll b) {
		ll val = 1;
		a %= mod;
		while (b > 0) {
			if (b % 2) val = mul(a, val);
			a = mul(a, a);
			b >>= 1;
		}
		return val % mod;
	}

	ll inv(ll a) {
		return poww(a, mod - 2);
	}
}

ll const maxn = 3e5 + 5;


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b; cin >> a >> b;
	if (b < a) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}
	return 0;	
}

/*
3
0 1
3 0
1 0
*/