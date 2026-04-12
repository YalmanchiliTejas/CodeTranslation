#include<bits/stdc++.h>
using namespace std;

template<long long mod>
class ModInt {
public:
	long long v;
	ModInt(long long v = 0) : v((v % mod + mod) % mod) {}
	ModInt operator+(ModInt t) {return ModInt((v + t.v) % mod);}
	ModInt operator-(ModInt t) {return ModInt((v - t.v + mod) % mod);}
	ModInt operator*(ModInt t) {return ModInt((v * t.v) % mod);}
	ModInt operator+=(ModInt t) {return *this = *this + t;} 
	ModInt operator-=(ModInt t) {return *this = *this - t;}
	ModInt operator*=(ModInt t) {return *this = *this * t;}
	ModInt operator-() {return ModInt(-v);}
	ModInt mpow(long long t) {
		if (t == 0) return ModInt(1);
		ModInt a = mpow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}
	ModInt inv() {mpow(mod - 2);}
	ModInt operator/(ModInt t) {return ModInt(v) * inv();}
	ModInt operator/=(ModInt t) {return *this = *this / t;}
	ModInt operator==(ModInt t) {return *this.v == t.v;}
	ModInt operator!=(ModInt t) {return *this.v != t.v;}
	friend ostream& operator<<(ostream& os, const ModInt& mi) {
		os << mi.v;
		return os;
	}
};

int main() {
	
	string n;
	cin >> n;
	int d;
	cin >> d;
	
	int szN = n.size();

	using mint = ModInt<1000000007>;

	

	vector<vector<vector<mint>>> dp(10005, vector<vector<mint>>(2, vector<mint>(105, 0)));

	
	

	//for (int i = 0; i < d; i++) dp[0][0][i] = 1;
	dp[0][0][0] = 1;
	for (int i = 0; i < szN; i++) {
		int vl = (n[i] - '0');
		for (int smaller = 0; smaller < 2; smaller++) {
			for (int j = 0; j < d; j++) {
				for (int k = 0; k < (smaller ? 10 : vl + 1); k++) {
					dp[i + 1][smaller || k < vl][(j + k) % d] += dp[i][smaller][j];
				}
			}
		}
	}

	cout << dp[szN][1][0] + dp[szN][0][0] - 1 << endl;
	
	return 0;
}
