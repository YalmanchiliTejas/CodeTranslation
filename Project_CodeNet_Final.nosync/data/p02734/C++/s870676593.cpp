#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>
#include <random>

#define FOR_LT(i, beg, end) for (int i = (int)(beg); i < (int)(end); i++)
#define FOR_LE(i, beg, end) for (int i = (int)(beg); i <= (int)(end); i++)
#define FOR_DW(i, beg, end) for (int i = (int)(beg); (int)(end) <= i; i--)
#define REP(n)              for (int repeat_index = 0; repeat_index < (int)n; repeat_index++)


using namespace std;


struct S {
	int i;
	int j;
	int s;
};


constexpr int64_t kRem = 998244353;


template<int64_t M = 1000000007>
class ModInt {
public:
	ModInt() : val_(0) {};

	ModInt(int64_t val) {
		this->val_ = val;
		this->val_ %= M;
		while (this->val_ >= M) this->val_ -= M;
	}

	operator int64_t() const {
		return this->val_;
	}

	ModInt& operator += (int64_t val) {
		this->val_ += val;
		this->val_ %= M;
		if (this->val_ >= M) this->val_ -= M;

		return *this;
	}

	ModInt& operator -= (int64_t val) {
		this->val_ -= val;
		this->val_ %= M;
		if (this->val_ < 0) this->val_ += M;

		return *this;
	}

	ModInt& operator *= (int64_t val) {
		this->val_ *= val;
		this->val_ %= M;

		return *this;
	}

	ModInt& operator /= (int64_t val) {
		ModInt v = ModInt(val).pow(M - 2);
		*this *= v;

		return *this;
	}

	ModInt operator + (int64_t v) const {
		ModInt ret = *this;
		return (ret += v);
	}

	ModInt operator - (int64_t v) const {
		ModInt ret = *this;
		return (ret -= v);
	}

	ModInt operator * (int64_t v) const {
		ModInt ret = *this;
		return (ret *= v);
	}

	ModInt operator / (int64_t v) const {
		ModInt ret = *this;
		return (ret /= v);
	}

	ModInt pow(int64_t m) const {
		if (m == 0) {
			ModInt ret(1);
			return ret;
		}
		if (m == 1) {
			ModInt ret(*this);
			return ret;
		}

		ModInt v = this->pow(m / 2);
		ModInt ret = v * v;
		if (m & 1) {
			ret *= (*this);
		}
		return ret;
	}

	ostream& operator << (ostream & out) {
		out << this->val_;
		return out;
	}

private:
	int64_t val_;
};

ModInt<kRem> dp[3001][3001][3] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int n, s; cin >> n >> s;
	vector<int> as(n); for (auto& a : as) cin >> a;
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= s; j++) {
			(dp[i + 1][j][0] += dp[i][j][0]);
			(dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1]);
			(dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]);
			if (j + as[i] <= s) {
				(dp[i + 1][j + as[i]][1] += dp[i][j][0] + dp[i][j][1]);
				(dp[i + 1][j + as[i]][2] += dp[i][j][0] + dp[i][j][1]);
			}
		}
	}

	cout << dp[n][s][2] << endl;

	return 0;
}