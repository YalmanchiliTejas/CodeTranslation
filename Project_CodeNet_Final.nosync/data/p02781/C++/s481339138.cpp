#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <math.h>
#include <cmath>
#include <ctime>
#include <stdlib.h>


using namespace std;

#define int long long
#define endl "\n"
#define all(v)  v.begin(),v.end()
#define fir first
#define sec second
#define m_p make_pair
#define m_t make_tuple
#define rep(i,n)  for(int i=0; i<(int) (n); i++)
#pragma once
typedef pair<int, int> P;
typedef long double ld;
typedef long long ll;

const double pai = 3.1415926535897;
const int mod = 1000000007;
const int INF = 1000000021;
const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];


//x未満の要素数を返す二分探索関数
int b_s(vector<int>& vec, int xx) {
	return lower_bound(all(vec), xx) - vec.begin();
}
template<typename T>void vecout(vector<T>& vec) { for (T t : vec) cout << t << " "; cout << endl; }
template<typename TT>void vecin(vector<TT>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}
}

// テーブルを作る前処理
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

//n個を1個以上のx組のグループに分ける重複組み合わせはcom(n-1,x-1)
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
long long modpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

bool chmax(int& xx, int yy) {
	if (xx < yy) {
		xx = yy;
		return true;
	}
	return false;
}
bool chmin(int& xx, int yy) {
	if (xx > yy) {
		xx = yy;
		return true;
	}
	return false;
}
double dist(int x, int y) {
	return sqrt(x * x + y * y);
}
double dist(int xx1, int xx2, int yy1, int yy2) {
	return sqrt(abs(xx1 - xx2) * abs(xx1 - xx2) + abs(yy1 - yy2) * abs(yy1 - yy2));
}
ll mypow(int nn, int kk) {
	ll xx = 1;
	rep(i, kk) {
		xx *= nn;
	}
	return xx;
}
int gcd(int xx, int yy) {
	int p = xx;
	int q = yy;
	if (q > p)swap(p, q);
	while (p % q != 0) {
		p %= q;
		swap(p, q);
	}
	return q;
}
int lcm(int xx, int yy) {
	return xx * yy / gcd(xx, yy);
}
bool prime(int xx) {
	if (xx <= 1) {
		return 0;
	}
	for (int i = 2; i * i <= xx; i++) {
		if (xx % i == 0) {
			return 0;
		}
	}
	return 1;
}

vector<int>vec;

int solve(int b,int m, int k) {//m桁以下で0出ない数字がちょうどK個あるようなものの個数
	if (m == 0) return 0;
	if (b == 1) {//10^m未満
		return COM(m, k) * mypow(9, k);
	}
	if (k == 1) {
		return (m-1)*9+vec[m-1];
	}
	int ma = 0, t = 0;
	rep(i,m-1) {
		if (i>=1) {
			t += 9 * solve(1, i, k - 1);
		}
		if (vec[i] > 0)ma = i+1;
	}
	t += ((int)vec[m - 1]-1) * solve(1, m - 1, k - 1);
	//cout << "(1, " << m - 1 << ", " << k - 1 << ") = " << solve(1, m - 1, k - 1) << endl;
	t += solve(0, ma, k - 1);
	//cout << "(0, " << ma << ", " << k - 1 << ") = " << solve(0, ma, k - 1) << endl;
	return t;
}

signed main() {
	COMinit();
	string s;
	int k,m;//mは桁数
	cin >> s >> k;
	vec.resize(s.size());//下からi+1桁目の数字vec[i]
	rep(i, s.size()) {
		vec[i] = s[s.size()-i-1] - '0';
	}
	m = s.size();
	//cout << COM(m, k) * mypow(9, k) << endl;
	cout << solve(0, m, k) << endl;
}