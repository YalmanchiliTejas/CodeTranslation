#define INPUT "./io/test.in"
#define OUTPUT "./io/test.out"
#ifdef NARUT_LOCAL
	#include "local.hpp"
	#include "reopen.hpp"
	#else
	#pragma GCC optimize("-O2", "-ftree-vectorize")
	#include <algorithm>
	#include <array>
	#include <bitset>
	#include <cassert>
	#include <cctype>
	#include <cmath>
	#include <complex>
	#include <cstdint>
	#include <cstdio>
	#include <cstdlib>
	#include <cstring>
	#include <deque>
	#include <exception>
	#include <functional>
	#include <initializer_list>
	#include <iomanip>
	#include <iostream>
	#include <iterator>
	#include <limits>
	#include <list>
	#include <locale>
	#include <map>
	#include <memory>
	#include <numeric>
	#include <queue>
	#include <random>
	#include <set>
	#include <sstream>
	#include <stack>
	#include <stdexcept>
	#include <tuple>
	#include <type_traits>
	#include <utility>
	#include <vector>
	using namespace std;
	#define DBG(...)
	#define DBG2(...)
	#define Debug(...)
	#define TM_(...) template <class __VA_ARGS__>
	#define ENABLE(...) TM_(T) static enable_if_t<__VA_ARGS__>
	#define SFINAE(name, ...)                                                                \
		TM_(, class = void) struct name##_s : false_type {};                                 \
		TM_(T) struct name##_s<T, decltype(void(__VA_ARGS__))> : true_type {};               \
		TM_(T) constexpr auto name = name##_s<T>::value;
	namespace narut {
	TM_(T) using TupSz = tuple_size<decay_t<T>>;
	SFINAE(Iterable, begin(declval<T &>()))
	SFINAE(IsTuple, TupSz<T>{})
	SFINAE(Coutable, cout << declval<T &>())
	SFINAE(Cinable, cin >> declval<T &>())
	TM_(, class = void) struct Spc { static const char val = '\n'; };
	TM_(T) struct Spc<T, enable_if_t<Coutable<T>>> { static const char val = ' '; };
	struct Ctx {
		ENABLE(Coutable<T>) Write(T const &t) { cout << t; }
		ENABLE(!Coutable<T> and Iterable<T>) Write(T const &t) {
			auto it = begin(t), e = end(t);
			if (it != e) Write(*it++);
			for (; it != e; Write(*it++)) cout << Spc<decltype(*it)>::val;
		}
		TM_(T, size_t... Is)
		static void WriteTup(T const &t, index_sequence<Is...>) {
			(void)(int[]){0, ((Is == 0) ? 0 : ((cout << ' '), 0), Write(get<Is>(t)), 0)...};
		}
		ENABLE(!Coutable<T> and !Iterable<T> and IsTuple<T>) Write(T const &t) {
			WriteTup(t, make_index_sequence<TupSz<T>::value>{});
		}
		ENABLE(Cinable<T>) Read(T &t) { cin >> t; }
		ENABLE(!Cinable<T> and Iterable<T>) Read(T &t) {
			for (auto &&x : t) Read(x);
		}
		TM_(T, size_t... Is) static void ReadTup(T &t, index_sequence<Is...>) {
			(void)(int[]){0, (Read(get<Is>(t)), 0)...};
		}
		ENABLE(!Cinable<T> and !Iterable<T> and IsTuple<T>) Read(T &t) {
			ReadTup(t, make_index_sequence<TupSz<T>::value>{});
		}
	};
	void Cout() { cout << '\n'; }
	TM_(F, class... Ts) void Cout(F const &f, Ts const &... ts) {
		Ctx::Write(f);
		(void)(int[]){0, (cout << ' ', Ctx::Write(ts), 0)...};
		cout << '\n';
	}
	TM_(T) T Cin() {
		T t;
		Ctx::Read(t);
		return t;
	}
	TM_(T) void Cin(T &t) { Ctx::Read(t); }
	TM_(T) void Cin(T &t, int n) {
		t.resize(n);
		Ctx::Read(t);
	}
	TM_(T) struct Big {
		constexpr operator T() const {
			T x = 0, mask = 0x3f;
			for (int i = 0; i < sizeof(T); i++) x |= mask << 8 * i;
			return x;
		}
	};
	} // namespace narut
	using narut::Big;
	using narut::Cin;
	using narut::Cout;
	using ll = long long;

	using uint = unsigned int;
#endif

template <class T, uint D> struct MultiVec {
	array<uint, D> dim = {};
	vector<T> arr;

	template <class... Ts> decltype(auto) operator()(Ts... ts) const {
		return arr[index<0>(0, ts...)];
	}
	template <class... Ts> decltype(auto) operator()(Ts... ts) { return arr[index<0>(0, ts...)]; }

	void Fill(T const &t) { fill(arr.begin(), arr.end(), t); }
	uint Size() const { return arr.size(); }
	
	template <class... Ts>
	void Resize(Ts... ts) {
		static_assert(sizeof...(ts) == D, "wrong reset sizes");
		dim = {static_cast<uint>(ts)...};
		arr.resize(index<0>(0, (ts - 1)...)+1);
	}

	explicit MultiVec() = default;
	template <class... Ts>
	explicit MultiVec(Ts... ts) : dim{static_cast<uint>(ts)...}, arr(index<0>(0, (ts - 1)...) + 1) {
		static_assert(sizeof...(ts) == D, "dimensions don't match");
	}

	auto begin() { return arr.begin(); }
	auto begin() const { return arr.begin(); }
	auto end() { return arr.end(); }
	auto end() const { return arr.end(); }
	auto rbegin() { return arr.rbegin(); }
	auto rbegin() const { return arr.rbegin(); }
	auto rend() { return arr.rend(); }
	auto rend() const { return arr.rend(); }

	template <uint d, class C, class F, class... Ts> uint index(C c, F f, Ts... ts) {
	#ifdef _GLIBCXX_DEBUG
		if (static_cast<uint>(f) >= dim[d])
			throw out_of_range(to_string(d + 1) + "th dimension indexing " + to_string(f) +
							   " but size = " + to_string(dim[d]));
	#endif
		return index<d + 1>(static_cast<uint>(c) * dim[d] + static_cast<uint>(f), ts...);
	}
	template <uint d> uint index(uint c) { 
        static_assert(d==D, "Wrong Indexing Dimension");
        return c; 
    }

    friend std::ostream& operator<<(std::ostream& os, MultiVec const& v) {
        for (uint i = 0; i < v.Size(); i++) {
            os << v.arr[i] << ' ';
            uint tmp = i + 1;
            for (uint d = D - 1; d > 0; d--) {
                if (tmp % v.dim[d]) break;
                os << '\n';
                tmp /= v.dim[d];
            }
        }
        return os;
    }
};

template <class T, class... Ts> auto MakeMultiVec(Ts... ts) {
	return MultiVec<T, sizeof...(Ts)>(ts...);
}



int n;
vector<int> A;
MultiVec<ll, 2> dp;

ll DP(int i, int j) {
	if (i >= j) return 0;
	if (dp(i,j-1) != -Big<ll>{}) return dp(i,j-1);
	
	ll f = A[i] - DP(i+1,j);
	ll s = A[j-1] - DP(i, j-1);
	
	return dp(i,j-1)=max(f,s);
}

auto Run() {
	cin>>n;
	Cin(A,n);
	dp.Resize(n,n);
	dp.Fill(-Big<ll>{});
	cout << DP(0, n);		
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(10);

	Run();
}

