#include "bits/stdc++.h"

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;

#define MOD 1000000007
// Modulo.h start----------------------------------------

#pragma once

#include <vector>

unsigned int mod;
struct Modint;
std::vector<Modint> fact_mod;
std::vector<Modint> rev_fact_mod;

using namespace std;

template<typename Tint>
Tint gcd(Tint a, Tint b) {
	// O(log max(a,b))
	a = abs(a);
	b = abs(b);
	return b != 0 ? gcd(b, a % b) : a;
}

template<typename Tint>
Tint lcm(Tint a, Tint b) {
	return a / gcd(a, b) * b;
}

// a x + b y = gcd(a, b)
int extgcd(const unsigned int a, const unsigned int b, int &x, int &y) {
	// O(log max(a,b))
	int g = a; x = 1; y = 0;
	if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
	return g;
}

void set_mod(const unsigned int m) {
	mod = m;
}
void set_mod(const int m) {
	if (m > 0)
		set_mod((unsigned int)m);
	else
		cout << "Error in set_mod" << endl;
}

unsigned int inv_mod(const unsigned int a) {
	int x, y;
	if (extgcd(a, mod, x, y) == 1)
		return (unsigned int)(((long long)x + mod) % mod);
	else // unsolvable
		return 0;
}

struct Modint {
	unsigned int value;
	Modint() { }
	Modint(unsigned int value) : value(value%mod) {	}
	Modint(int value) : Modint((unsigned int)(value % mod + mod)) {	}
	Modint(const Modint& rhs) : Modint(rhs.value) { }
	bool operator==(const Modint& rhs) const;
	inline bool operator!=(const Modint& rhs) const
	{
		return !(*this == rhs);
	}
	Modint& operator+=(const Modint& rhs);
	Modint& operator+=(const unsigned int rhs);
	Modint& operator+=(const int rhs);
	Modint& operator-=(const Modint& rhs);
	Modint& operator-=(const unsigned int rhs);
	Modint& operator-=(const int rhs);
	Modint& operator*=(const Modint& rhs);
	Modint& operator*=(const unsigned int rhs);
	Modint& operator*=(const unsigned long long rhs);
	Modint& operator*=(const int rhs);
	Modint& operator/=(const Modint& rhs);
	Modint& operator/=(const unsigned int rhs);
	Modint& operator/=(const int rhs);
};
bool Modint::operator==(const Modint& rhs) const
{
	return value == rhs.value;
}
Modint& Modint::operator+=(const Modint& rhs)
{
	(*this) += rhs.value;
	return *this;
}
Modint& Modint::operator+=(const unsigned int rhs)
{
	unsigned long long tmp = this->value;
	tmp += rhs;
	tmp %= mod;
	this->value = (unsigned int)tmp;
	return *this;
}
Modint& Modint::operator+=(const int rhs)
{
	(*this) += (unsigned int)(rhs % mod + mod);
	return *this;
}
Modint& Modint::operator-=(const Modint& rhs)
{
	(*this) -= rhs.value;
	return *this;
}
Modint& Modint::operator-=(const unsigned int rhs)
{
	*this += mod - rhs % mod;
	return *this;
}
Modint& Modint::operator-=(const int rhs)
{
	*this -= (unsigned int)(rhs % mod + mod);
	return *this;
}
Modint& Modint::operator*=(const Modint& rhs)
{
	(*this) *= rhs.value;
	return *this;
}
Modint& Modint::operator*=(const unsigned int rhs)
{
	unsigned long long tmp = this->value;
	tmp *= rhs;
	tmp %= mod;
	this->value = (unsigned int)tmp;
	return *this;
}
Modint& Modint::operator*=(const unsigned long long rhs)
{
	unsigned long long tmp = this->value;
	tmp *= rhs;
	tmp %= mod;
	this->value = (unsigned int)tmp;
	return *this;
}
Modint& Modint::operator*=(const int rhs)
{
	(*this) *= (unsigned int)(rhs % mod + mod);
	return *this;
}
Modint& Modint::operator/=(const Modint& rhs)
{
	(*this) /= rhs.value;
	return *this;
}
Modint& Modint::operator/=(const unsigned int rhs)
{
	*this *= inv_mod(rhs);
	return *this;
}
Modint& Modint::operator/=(const int rhs)
{
	*this /= (unsigned int)(rhs % mod + mod);
	return *this;
}
const Modint operator + (const Modint& lhs, const Modint& rhs) {
	return Modint(lhs) += rhs;
}
const Modint operator + (const Modint& lhs, unsigned int rhs) {
	return Modint(lhs) += rhs;
}
const Modint operator + (unsigned int lhs, const Modint& rhs) {
	return Modint(lhs) += rhs;
}
const Modint operator - (const Modint& lhs, const Modint& rhs) {
	return Modint(lhs) -= rhs;
}
const Modint operator - (const Modint& lhs, unsigned int rhs) {
	return Modint(lhs) -= rhs;
}
const Modint operator - (unsigned int lhs, const Modint& rhs) {
	return Modint(lhs) -= rhs;
}
const Modint operator * (const Modint& lhs, const Modint& rhs) {
	return Modint(lhs) *= rhs;
}
const Modint operator * (const Modint& lhs, unsigned int rhs) {
	return Modint(lhs) *= rhs;
}
const Modint operator * (unsigned int lhs, const Modint& rhs) {
	return Modint(lhs) *= rhs;
}
const Modint operator / (const Modint& lhs, const Modint& rhs) {
	return Modint(lhs) /= rhs;
}
const Modint operator / (const Modint& lhs, unsigned int rhs) {
	return Modint(lhs) /= rhs;
}
const Modint operator / (unsigned int lhs, const Modint& rhs) {
	return Modint(lhs) /= rhs;
}
ostream& operator<<(std::ostream& lhs, const Modint& rhs)
{
	lhs << rhs.value;
	return lhs;
}

Modint pow_mod(const Modint& x, const unsigned int k) { //x^k (mod)
	if (k == 0)     return Modint(1);
	if (k % 2 == 0) return pow_mod(x*x, k / 2);
	else            return x * pow_mod(x, k - 1);
}
Modint pow_mod(const unsigned int x, const unsigned int k) {
	return pow_mod(Modint(x), k);
}

std::vector<Modint> set_fact_mod(unsigned int n) {
	fact_mod = vector<Modint>(n + 1);
	fact_mod[0] = 1;
	for (unsigned int i = 1; i <= n; i++)
	{
		fact_mod[i] = fact_mod[i - 1] * i;
	}
	return fact_mod;
}

std::vector<Modint> set_rev_fact_mod(unsigned int n) {
	rev_fact_mod = vector<Modint>(n + 1);
	rev_fact_mod[n] = 1 / fact_mod[n];
	for (int i = n - 1; i >= 0; i--)
	{
		rev_fact_mod[i] = rev_fact_mod[i + 1] * (unsigned int)(i + 1);
	}
	return rev_fact_mod;
}

Modint combination_mod_precalculation(unsigned int n, unsigned int r) {
	//set mod, fact_mod, rev_fact_mod
	return fact_mod[n] * rev_fact_mod[r] * rev_fact_mod[n - r];
}

Modint combination_mod_straightforward(unsigned long long n, unsigned long long r) { //mod is prime
	if (r * 2 > n) r = n - r;
	Modint numerator = 1;
	Modint denominator = 1;
	for (unsigned long long i = 1; i <= r; ++i) {
		numerator *= n - i + 1;
		denominator *= i;
	}
	return numerator / denominator;
}

// Modulo.h end----------------------------------------------

int main() {
	int N, M;
	ll K;
	cin >> N >> M >> K;
	set_mod(MOD);

	vector<Modint> dp(max(N, M) + 1);
	dp[1] = 0;
	for (int i = 2; i <= max(N, M); i++)
	{
		dp[i] = dp[i - 1] + (Modint)(i - 1) * i / 2 * 2;
	}

	Modint ans = combination_mod_straightforward((ll)N * M - 2, K - 2);
	ans *= (Modint)N * N * dp[M] + (Modint)M * M * dp[N];
	ans /= 2;

	cout << ans << endl;
	return 0;
}