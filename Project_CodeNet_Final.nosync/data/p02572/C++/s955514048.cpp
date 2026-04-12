#include <bits/stdc++.h>
#include <random>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using Pt = pair<int, int>;

namespace
{
	struct modint
	{
		static constexpr ll MOD = 1000000007;
		ll x_;
		modint() : x_(0) {}
		modint(ll x) : x_(x% MOD) {}
		modint& operator+=(const modint& src)
		{
			if ((x_ += src.x_) >= MOD)
				x_ -= MOD;
			return *this;
		}
		modint& operator-=(const modint& src)
		{
			if ((x_ += MOD - src.x_) >= MOD)
				x_ -= MOD;
			return *this;
		}
		modint& operator*=(const modint& src)
		{
			(x_ *= src.x_) %= MOD;
			return *this;
		}

		modint& operator/=(const modint& src)
		{
			return (*this) *= src.inv();
		}
		modint inv() const
		{
			return pow(MOD - 2);
		}
		modint pow(ll t) const
		{
			if (t == 0)
				return 1;
			modint a = pow(t >> 1);
			a *= a;
			if (t & 1)
				a *= *this;
			return a;
		}
	};
}

int main()
{
	ll MOD = 1000000007;
	int N;
	cin >> N;
	vl A(N);
	for (auto& x : A)
		cin >> x;
	modint sum = 0;
	modint sqSum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += A[i];
		ll x = A[i] * A[i];
		x %= MOD;
		sqSum += x;
	}
	modint sumSq = sum;
	sumSq *= sum;
	sumSq -= sqSum;
	sumSq /= 2;
	cout << sumSq.x_ << endl;
	return 0;
}
