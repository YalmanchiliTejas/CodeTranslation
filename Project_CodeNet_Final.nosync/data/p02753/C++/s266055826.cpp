#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<limits.h>
#include<cmath>
#include<queue>
#include<stack>

#include<stdio.h>
#include<stdlib.h>

#define rep(i,n) for(ll i = 0; i < (ll)n; i++)
#define swap(a,b) a^=b;b^=a;a^=b;
#define chmax(a,b) {if(a < b) a = b;}
#define chmin(a,b) {if(a > b) a = b;}

using namespace std;
typedef long long ll;
ll gcd(ll, ll);
vector<bool> to_binary(int);
ll nCr(ll n, ll r);

const ll INF = 1LL << 60;

typedef tuple<ll, ll> mtupl;

/*

bool mycomp(mtupl x, mtupl y) {
	return get<1>(x) < get<1>(y);
}

int vsum(vector<int> v) {
	int res = 0;
	for (auto it = v.begin(); it != v.end(); it++)
		res += *it;
	return res;
}

int vmin(vector<int> v) {
	int min = INT32_MAX;
	for (auto it = v.begin(); it != v.end(); it++)
		min = std::min(min, *it);
	return min;
}

int vmax(vector<int> v) {
	int max = INT32_MIN;
	for (auto it = v.begin(); it != v.end(); it++)
		max = std::max(max, *it);
	return max;
}

ll gcd(ll A, ll B) {
	if (A == 0 || B == 0) return max(A, B);
	int r = A % B;
	while (r != 0) {
		A = B;
		B = r;
		r = A % B;
	}
	return B;
}

vector<ll> prime_factor(int64_t n) {
	//map< ll, ll > ret;
	vector<ll> ret;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			//ret[i]++;
			ret.push_back(i);
			n /= i;
		}
	}
	if (n != 1)ret.push_back(n);// ret[n] = 1;
	return ret;
}

const int MAX = 1000000;
const int MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
ll COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

struct edge {
	ll to;
	ll cost;
};

*/

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//Program Start	

	string s;
	cin >> s;
	if (s[0] == s[1] && s[0] == s[2]) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

ProgramEndPointLabel:;

	//Program End
#ifndef DEBUG
	system("pause");
#endif // !DEBUG


	return 0;
}


