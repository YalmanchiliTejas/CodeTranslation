#include <bits/stdc++.h>
using namespace std;

template<int MOD>
class mod_int {
	unsigned x;
public:
	mod_int() : x(0) { }
	mod_int(int sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	mod_int(long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	mod_int &operator+=(mod_int that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	mod_int &operator-=(mod_int that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	mod_int &operator*=(mod_int that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	mod_int &operator/=(mod_int that) { return *this *= that.inverse(); }

	mod_int operator+(mod_int that) const { return mod_int(*this) += that; }
	mod_int operator-(mod_int that) const { return mod_int(*this) -= that; }
	mod_int operator*(mod_int that) const { return mod_int(*this) *= that; }
	mod_int operator/(mod_int that) const { return mod_int(*this) /= that; }

	bool operator==(const mod_int& that) const { return x == that.x; }

	mod_int inverse() const {
		long long a = x, b = MOD, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		return mod_int(u);
	}
};

template<int MOD>
istream& operator >> (istream& is, mod_int<MOD>& val) {
	long long x;
	is >> x; val = x;
	return is;
}

template<int MOD>
ostream& operator << (ostream& os, const mod_int<MOD>& val) {
	os << val.get();
	return os;
}

const int mod = 1e9 + 7;
using mint = mod_int<mod>;

int main()
{
	string K;
	int D;
	cin >> K >> D;
	int N = K.size();
	vector<vector<vector<mint>>> dp(N + 1, vector<vector<mint>>(D, vector<mint>(2)));
	dp[0][0][0] = 1;
	for (int i = 0; i < N; i++) {
		int x = K[i] - '0';
		for (int j = 0; j < D; j++) {
			for (int b = 0; b < 2; b++) {
				int lim = b ? 9 : x;
				for (int d = 0; d <= lim; d++) {
					dp[i + 1][(j + d) % D][b || d < lim] += dp[i][j][b];
				}
			}
		}
	}
	mint res = dp[N][0][0] + dp[N][0][1] - 1;
	cout << res << endl;
	return 0;
}
