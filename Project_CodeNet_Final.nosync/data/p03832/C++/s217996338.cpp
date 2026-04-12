#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <vector>
//#include <array>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <stack>
//#include <queue>
using ll = long long;
using namespace std;

#define MOD 1000000007
unsigned int mod;
std::vector<unsigned int> fact_mod;
std::vector<unsigned int> rev_fact_mod;

using namespace std;

template<typename Tint>
Tint gcd(Tint a, Tint b) {
	// O(log max(a,b))
	return b != 0 ? gcd(b, a % b) : a;
}

template<typename Tint>
Tint lcm(Tint a, Tint b) {
	return a / gcd(a, b) * b;
}

// a x + b y = gcd(a, b)
template<typename Tint>
Tint extgcd(Tint a, Tint b, Tint &x, Tint &y) {
	// O(log max(a,b))
	Tint g = a; x = 1; y = 0;
	if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
	return g;
}

void set_mod(const int m) {
	mod = m;
}

template<typename Tint>
Tint inv_mod(Tint a) {
	Tint x, y;
	if (extgcd(a, mod, x, y) == 1)
		return (x + mod) % mod;
	else // unsolvable
		return 0;
}


unsigned int pow_mod(const unsigned long long x, const unsigned int k) { //x^k (mod mod) 
	if (k == 0)     return 1;
	if (k % 2 == 0) return pow_mod(x*x % mod, k / 2);
	else            return x * pow_mod(x, k - 1) % mod;
}

std::vector<unsigned int> set_fact_mod(unsigned int n) {
	fact_mod = vector<unsigned int>(n + 1);
	fact_mod[0] = 1;
	for (unsigned int i = 1; i <= n; i++)
	{
		fact_mod[i] = (long long)fact_mod[i - 1] * i % mod;
	}
	return fact_mod;
}

std::vector<unsigned int> set_rev_fact_mod(unsigned int n) {
	rev_fact_mod = vector<unsigned int>(n + 1);
	rev_fact_mod[n] = pow_mod(fact_mod[n], mod - 2);
	for (int i = n - 1; i >= 0; i--)
	{
		rev_fact_mod[i] = (long long)rev_fact_mod[i + 1] * (i + 1) % mod;
	}
	return rev_fact_mod;
}
int main() {
	unsigned int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	set_mod(MOD);
	set_fact_mod(n);
	set_rev_fact_mod(n);

	vector<unsigned int>dp(n + 1, 0);
	dp[0] = 1;
	for (unsigned int tmpb = a; tmpb <= b; tmpb++)
	{
		for (unsigned int tmpn = n; tmpn >= 1; tmpn--)
		{
			unsigned int sum_tmpb_tmpn = 0;
			for (unsigned int tmpk = c; tmpk <= min(tmpn / tmpb, d); tmpk++)
			{
				unsigned int tmprest = tmpn - tmpb * tmpk;
				ll cal;
				ll comb_tmpb = fact_mod[tmpn];
				comb_tmpb *= pow_mod(rev_fact_mod[tmpb], tmpk);
				comb_tmpb %= MOD;
				comb_tmpb *= rev_fact_mod[tmprest];
				comb_tmpb %= MOD;
				comb_tmpb *= rev_fact_mod[tmpk];
				comb_tmpb %= MOD;
				cal = dp[tmprest] * comb_tmpb;
				cal %= MOD;
				cal += sum_tmpb_tmpn;
				cal %= MOD;
				sum_tmpb_tmpn = cal;
			}
			dp[tmpn] = (dp[tmpn] + sum_tmpb_tmpn) % MOD;
		}
	}

	cout << dp[n] << endl;

	return 0;
}