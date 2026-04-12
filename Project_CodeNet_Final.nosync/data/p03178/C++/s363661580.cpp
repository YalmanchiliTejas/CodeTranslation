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


using ll = long long;
const ll mod = 1000000007;
using mint = ModInt<mod>;

int d;
mint dp1[100005][100], dp2[100005][100];
//dp1[i][j] := i桁まで見終わったときに次に0~9が使え、i桁までの数字の和のmod100がj




int main() {
	string k;
	cin >> k;
	cin >> d;

	int szk = k.size();
	
	int a[szk + 1];
	for (int i = 1; i <= szk; i++) a[i] = k[i - 1] - '0';

	dp2[0][0] = 1;
	for (int i = 1; i <= szk; i++) {
		for (int j = 0; j < d; j++) {
			for (int x = 0; x < 10; x++) {
				dp1[i][(j + x) % d] += dp1[i - 1][j];
				if (x < a[i]) {
					dp1[i][(j + x) % d] += dp2[i - 1][j];
				}
				if (x == a[i]) {
					dp2[i][(j + x) % d] += dp2[i - 1][j];
				}
			}
		}
	}

	cout << dp1[szk][0] + dp2[szk][0] - 1 << endl;
	return 0;
}