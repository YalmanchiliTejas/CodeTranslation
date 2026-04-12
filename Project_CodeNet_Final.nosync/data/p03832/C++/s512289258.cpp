#include <utility>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
namespace loquat {
template <typename T>
static std::pair<T, T> extended_gcd(T a, T b){
	if(b == 0){ return std::pair<T, T>(1, 0); }
	const auto p = extended_gcd(b, a % b);
	return std::pair<T, T>(p.second, p.first - a / b * p.second);
}
}
namespace loquat {
template <int MOD>
class modulus_integer {
public:
	typedef modulus_integer<MOD> self_type;
private:
	int m_value;
	static self_type unsafe_construct(int x){
		self_type y;
		y.m_value = x;
		return y;
	}
public:
	modulus_integer()
		: m_value(0)
	{ }
	modulus_integer(int x)
		: m_value(x % MOD)
	{
		if(m_value < 0){ m_value += MOD; }
	}
	int operator*() const { return m_value; }
	self_type& operator=(const self_type& x){
		m_value = x.m_value;
		return *this;
	}
	bool operator==(const self_type& x) const {
		return m_value == x.m_value;
	}
	self_type operator+(const self_type& x) const {
		const int y = m_value + x.m_value;
		return unsafe_construct(y >= MOD ? y - MOD : y);
	}
	self_type operator*(const self_type& x) const {
		return unsafe_construct(
			static_cast<long long>(m_value) * x.m_value % MOD);
	}
	self_type operator/(const self_type& x) const {
		return (*this) * self_type(extended_gcd(x.m_value, MOD).first);
	}
	self_type& operator+=(const self_type& x){
		return (*this = *this + x);
	}
};
template <int MOD>
inline std::ostream& operator<<(
	std::ostream& os, const modulus_integer<MOD>& x)
{
	os << *x;
	return os;
}
}
using namespace std;
using mint = loquat::modulus_integer<1000000007>;
static const int MAX_N = 1000;
int main(){
	ios_base::sync_with_stdio(false);
	vector<mint> factorial(MAX_N + 1), inv_factorial(MAX_N + 1);
	factorial[0] = inv_factorial[0] = mint(1);
	for(int i = 1; i <= MAX_N; ++i){
		factorial[i] = factorial[i - 1] * mint(i);
		inv_factorial[i] = mint(1) / factorial[i];
	}
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	vector<mint> cur(n + 1);
	cur[0] = mint(1);
	for(int i = a; i <= b; ++i){
		vector<mint> next(cur);
		for(int j = 0; j < n; ++j){
			if(cur[j] == mint(0)){ continue; }
			const int r = n - j, lim = r / i;
			vector<mint> local(lim + 1);
			local[0] = mint(1);
			for(int k = 0; k < lim; ++k){
				const int rr = r - k * i;
				const auto comb =
					factorial[rr] * inv_factorial[rr - i] * inv_factorial[i];
				local[k + 1] = local[k] * comb;
			}
			for(int k = c; k <= lim && k <= d; ++k){
				const int jj = j + k * i;
				next[jj] += cur[j] * local[k] * inv_factorial[k];
			}
		}
		cur = std::move(next);
	}
	cout << cur[n] << endl;
	return 0;
}
