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
using namespace std;

#define int long long
#define endl "\n"
#define all(v)  v.begin(),v.end()
#define fir first
#define sec second
#define fro front
#define m_p make_pair
#define rep(i,n)  for(int i=0; i<(int) (n); i++)
#define vecin(v) for(int i=0; i<(int)v.size(); i++)cin>>v[i];

const int mod = 2019;
const int INF = 2000000015;
const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
int jousu(int x00, int y00) {
	int z00 = 1;
	for (int i = 0; i < y00; i++) {
		z00 *= x00;
	}
	return z00;
}
int keta(int x00) {
	int z00 = x00;
	int w00 = 0;
	while (z00 != 0) {
		z00 /= 10;
		w00++;
	}
	return w00;
}
int krag(double xx) {
	return INF - (int)(INF - xx);
}


int modinv(int a, int m) {
	int b = m, u = 1, v = 0;
	while (b) {
		int t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
int modpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) res=res* a% mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
int com(int xx, int yy) {
	int zz = 1;
	for (int i = xx; i > xx - yy; i--) {
		zz *= i;
		zz %= mod;
	}
	for (int i = 1; i <= yy; i++) {
		zz *= modinv(i, mod);
		zz %= mod;
	}
	return zz;
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
	int a = xx;
	for (int i = 2; i * i <= xx; i++) {
		if (xx % i == 0) {
			return 0;
		}
	}
	return 1;
}



signed main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>>vec(h, vector<char>(w));
	set<int>vec2;
	set<int>vec3;
	rep(i, h) {
		rep(j, w) {
			cin >> vec[i][j];
		}
	}
	rep(i, h) {
		rep(j, w) {
			if (vec[i][j] == '#') {
				goto skip;
			}
		}
		vec2.insert(i);
		skip:;
	}
	rep(i, w) {
		rep(j, h) {
			if (vec[j][i] == '#') {
				goto skip2;
			}
		}
		vec3.insert(i);
	skip2:;
	}
	rep(i, h) {
		if (vec2.count(i)) {
			continue;
		}
		rep(j, w) {
			if (vec3.count(j)) continue;
			cout<< vec[i][j];
		}
		cout << endl;
	}
}