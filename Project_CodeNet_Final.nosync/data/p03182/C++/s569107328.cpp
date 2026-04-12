//#include "pch.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <random>
#include <bitset>
#include <memory>
#define show(x) std::cerr << #x << " = " << (x) << std::endl
using ll = long long;
using ld = long double;
constexpr ll MOD = 1000000007LL;
template <typename T>
constexpr T INF() { return std::numeric_limits<T>::max() / 16; }
std::mt19937 mt{ std::random_device{}() }; 
template <typename Base>
class LazySeg
{
	static std::size_t SZ(const std::size_t n)
	{
		std::size_t ans = 1;
		for (; ans < n; ans <<= 1) {}
		return ans;
	}

public:
	using BaseAlgebra = Base;
	using ValMonoid = typename BaseAlgebra::ValMonoid;
	using OpMonoid = typename BaseAlgebra::OpMonoid;
	using T = typename BaseAlgebra::T;
	using F = typename BaseAlgebra::OpMonoid::T;
	LazySeg(const std::size_t n) : size(n), half(SZ(n)), value(half << 1, ValMonoid::id()), action(half << 1, OpMonoid::id()) {}
	template <typename InIt>
	LazySeg(const InIt first, const InIt last) : size(distance(first, last)), half(SZ(size)), value(half << 1, ValMonoid::id()), action(half << 1, OpMonoid::id())
	{
		copy(first, last, value.begin() + half);
		for (std::size_t i = half - 1; i >= 1; i--) { up(i); }
	}
	T get(const std::size_t a) const { return accumulate(a, a + 1); }
	void set(std::size_t a, const T& val)
	{
		modify(a, a + 1, OpMonoid::id()), value[a += half] = val;
		while (a >>= 1) { up(a); }
	}
	T accumulate(const std::size_t L, const std::size_t R) const
	{
		auto arec = [&](auto&& self, const std::size_t index, const std::size_t left, const std::size_t right) -> T {
			if (L <= left and right <= R) {
				return value[index];
			}
			else if (right <= L or R <= left) {
				return ValMonoid::id();
			}
			else {
				return act(action[index], acc(self(self, index << 1, left, (left + right) >> 1), self(self, index << 1 | 1, (left + right) >> 1, right)));
			}
		};
		return arec(arec, 1, 0, half);
	}
	void modify(const std::size_t L, const std::size_t R, const F& f)
	{
		auto mrec = [&](auto&& self, const std::size_t index, const std::size_t left, const std::size_t right) -> void {
			if (L <= left and right <= R) {
				this->update(index, f);
			}
			else if (right <= L or R <= left) {
			}
			else {
				this->update(index << 1, action[index]), this->update(index << 1 | 1, action[index]);
				self(self, index << 1, left, (left + right) >> 1), self(self, index << 1 | 1, (left + right) >> 1, right);
				this->up(index), action[index] = OpMonoid::id();
			}
		};
		mrec(mrec, 1, 0, half);
	}
	std::vector<T> data() const
	{
		std::vector<T> ans(size);
		for (std::size_t i = 0; i < size; i++) { ans[i] = get(i); }
		return ans;
	}

private:
	void up(const std::size_t i) { value[i] = acc(value[i << 1], value[i << 1 | 1]); }
	void update(const std::size_t i, const F& f) { value[i] = act(f, value[i]), action[i] = compose(f, action[i]); }
	const std::size_t size, half;
	std::vector<T> value;
	std::vector<F> action;
	const ValMonoid acc{};
	const OpMonoid compose{};
	const BaseAlgebra act{};
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const LazySeg<T>& seg)
{
	os << "[";
	for (const auto& e : seg.data()) { os << e << ","; }
	return (os << "]" << std::endl);
}
struct Max_Plus
{
	using X = ll;
	using T = X;
	struct ValMonoid
	{
		T operator()(const T& a, const T& b) const { return std::max(a, b); }
		static constexpr T id() { return -INF<T>(); }
	};
	struct OpMonoid
	{
		using X = ll;
		using T = X;
		T operator()(const T& f1, const T& f2) const { return f1 + f2; }
		static constexpr T id() { return 0; }
	};
	T operator()(const OpMonoid::T& f, const T& x) const { return f + x; }
	/** @cond TEST */
	static T RandomVal(std::uniform_int_distribution<T>& dist) { return dist(mt); }
	static OpMonoid::T RandomOp(std::uniform_int_distribution<OpMonoid::T>& dist) { return dist(mt); }
	/** @endcond */
};
int main()
{
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<int>> rl(N);
	std::vector<std::vector<ll>> ra(N);
	for (int i = 0; i < M; i++) {
		int l, r;
		ll a;
		std::cin >> l >> r >> a, l--,r--,rl[r].push_back(l), ra[r].push_back(a);
	}
	std::vector<ll> v(N, 0LL);
	LazySeg<Max_Plus> dp(v.begin(),v.end());
	for (int i = 0; i < N; i++) {
		dp.set(i, std::max(dp.get(i), dp.accumulate(0, i)));
		for (int j = 0; j < rl[i].size(); j++) {
			const int l = rl[i][j];
			const ll a = ra[i][j];
			dp.modify(l, i + 1, a);
		}
	}
	std::cout << std::max(0LL,dp.accumulate(0, N)) << std::endl;
}