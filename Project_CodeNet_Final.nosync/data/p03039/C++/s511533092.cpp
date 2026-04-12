#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

template<Int Mod = 1000000007> class modint{
public:
	Int val;
	constexpr modint(const Int x = 0) : val(x % Mod) {if(val < 0) val += Mod;}
	constexpr modint operator+(const modint rhs) const {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const {
		return modint(*this) *= rhs;
	}
	constexpr modint operator/(const modint rhs) const {
		return modint(*this) /= rhs;
	}
	constexpr modint operator+(const Int rhs) const {
		return modint(*this) += modint(rhs);
	}
	constexpr modint operator-(const Int rhs) const {
		return modint(*this) -= modint(rhs);
	}
	constexpr modint operator*(const Int rhs) const {
		return modint(*this) *= modint(rhs);
	}
	constexpr modint operator/(const Int rhs) const {
		return modint(*this) /= modint(rhs);
	}
	constexpr modint operator-() const {
		return modint(Mod - val);
	}
	constexpr modint &operator+=(const modint rhs){
		val += rhs.val;
		if(val >= Mod) val -= Mod;
		return *this;
	}
	constexpr modint &operator-=(const modint rhs){
		if(val < rhs.n) val += Mod;
		val -= rhs.n;
		return *this;
	}
	constexpr modint &operator*=(const modint rhs){
		val *= rhs.val;
		val %= Mod;
		return *this;
	}
	constexpr modint &operator/=(const modint rhs){
		return *this *= inv(rhs);
	}
	constexpr modint &operator++(){
		++val;
		if(val == Mod) val = 0;
		return *this;
	}
	constexpr modint &operator--(){
		--val;
		if(val == -1) val = Mod - 1;
		return *this;
	}
	constexpr modint operator<<(const Int rhs) const {
		return modint(*this) << rhs;
	}
	constexpr modint operator>>(const Int rhs) const {
		return modint(*this) >> rhs;
	}
	constexpr modint &operator<<=(const Int rhs){
		val <<= rhs;
		val %= Mod;
		return *this;
	}
	constexpr modint &operator>>=(const Int rhs){
		val >>= rhs;
		val %= Mod;
		return *this;
	}
	constexpr bool operator==(const modint rhs) const {
		return val == rhs.val;
	}
	constexpr bool operator!=(const modint rhs) const {
		return val != rhs.val;
	}
	constexpr bool operator<(const modint rhs) const {
		return val < rhs.val;
	}
	constexpr bool operator>(const modint rhs) const {
		return val > rhs.val;
	}
	constexpr bool operator<=(const modint rhs) const {
		return val <= rhs.val;
	}
	constexpr bool operator>=(const modint rhs) const {
		return val >= rhs.val;
	}
	friend ostream& operator<<(ostream& os, const modint<Mod>& m){
		return os << m.val;
	}
	friend istream& operator>>(istream& is, modint<Mod>& m){
		return is >> m.val;
	}
	static constexpr modint inv(modint m){
		Int a = m.val, b = Mod, u = 1, v = 0;
		while(b){
			Int t = a / b;
			a -= t * b;
			swap(a, b);
			u -= t * v;
			swap(u, v);
		}
		u %= Mod;
		if(u < 0) u += Mod;
		return modint(u);
	}
	constexpr operator Int() const {
		return val;
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	using mint = modint<>;
	Int n, m, k; cin >> n >> m >> k;
	mint ans(0);
	for(Int i=1; i<n; ++i) ans += mint(i) * (n-i) * m * m;
	for(Int i=1; i<m; ++i) ans += mint(i) * (m-i) * n * n;
	for(Int i=1; i<=k-2; ++i){
		ans *= (n * m - 1 - i);
		ans /= i;
	}
	cout << ans << "\n";
}