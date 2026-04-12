//
//                               S i r o t a n   w a t c h e s   o v e r   y o u .
//
//                                          ...Jggg+J+JJJg@NQmgJa.....,       
//                                 ....gH@@@@HHB""""7"YYYYHMMMMMMM@@@@@@@Hma,.   
//                            ...JH@@MMHY"!                        ? __""YH@@@@N&...     
//                        ..JH@@HY"~                                          _TW@@@Mme.    
//                     .Jg@@#"=                                                   _TTM@@N..     
//                  .Jg@@MY!                                                          ?T@@@h,.   
//                .-@@@B!                                                                (TM@@@L     
//              .(H@MY                                                                      ?W@@@+    
//             .W@@@                                                                          .T@@@[       
//           .d@@M!                                                                             .T@@N,   
//          .d@M@'                                                                                -W@@o. 
//         (@@M\                                                                                    ?M@N,
//        -d@M%                    ..,                                      ..,                      j@@b  
//       d@@M=                     TM9                                      ?MD                       W@@[ 
//      .H@M:                                                                                         .W@H,
//      H@Ht                                                                                           ,@@#   
//     (@@M~                                                                                           .@@h.
//    .@@M%                        ..gmHHJ.                             .JdHga.                        .H@@e  
//    j@@#_                       .@@@@@@@b                            J@@@@@@@h.                      .H@@\ 
//    d@@@                       .4@@@@@@MF                            (@@@@@@@@                        H@@b  
//    d@@[                         ?"BMY"=            .d@@@@H,          ?TWHHY"!                        d@@e    
//    J@@b          .JJJ-..,                         ,@@@@@@M%                       .........         -@@@M. 
//    ?@@M\         ?YHHM@@@@b                ..      .W@@HP                        X@@HMWY"=          d@@@#
//    ,@@@L.                                 ?H@Ng&+gd@@#H@@NHaJ+gH@[                                  J@@@] 
//     X@@@[            ......                 ?"YYYYY""   ?"YHHHB"^                 .....            (@@@#   
//      WH@N+.      .W@@@@MHB=                                                      .TWH@M@Hmc       .H@@M~    
//     .H@@@@N,      _!~                                                                            .d@@@N,   
//   .J@@#T@@@N,                                                                                  .d@@@@@@@b. 
//  (@@@@! .T@@@n,                                                                              .(H@@@H>.W@@@x  
// (@@@F      4@@@@MaJ.                                                                       .d@@@@Y77   4@@@r 
//.H@@P         ?TM@@@@N...                                                               .-JH@HMY=        d@@N,
//(@@@F             ?"WM@@@MQa-,.                                                  .(J(JN@@M#"             Z@@@L
// d@@H,                 (M@@@@@@@Ng&maJ....                           .. ...J.J+W@@@@@@HY!               .dH@b 
// ?M@@@N&.        ..(JW@@@MM"?7""TYHMH@@HH@@@@@HHHgkHagHa(mggdmmagH@H@@Q@@HMMMHY"7!TMM@@@HaJ,.        ..H@@@M^ 
//   ?"W@@@@MN@@@@@H@@MMY"                  _???!"= ?WMMBYYTMH=7""Y@""?"~^             _"YM@@@@@@@@MH@@@@@#"^ 
//       ?77WMMMYB""!                                                                        _7"WWMMMY"7=     

// need
#include <iostream>
#include <algorithm>
// data structure
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
//#include <deque>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#include <array>
// etc
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>
#include <fstream>

//std::ifstream ifs("b.in");
//auto& scan_in = ifs;
auto& scan_in = std::cin;

// input
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t) { scan_in >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest& ...rest) { scan_in >> first; MACRO_VAR_Scan(rest...); }
#define VEC_ROW(type, n, ...)std::vector<type> __VA_ARGS__;MACRO_VEC_ROW_Init(n, __VA_ARGS__); for(int w_=0; w_<n; ++w_){MACRO_VEC_ROW_Scan(w_, __VA_ARGS__);}
template<typename T> void MACRO_VEC_ROW_Init(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Init(int n, First& first, Rest& ...rest) { first.resize(n); MACRO_VEC_ROW_Init(n, rest...); }
template<typename T> void MACRO_VEC_ROW_Scan(int p, T& t) { scan_in >> t[p]; }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Scan(int p, First& first, Rest& ...rest) { scan_in >> first[p]; MACRO_VEC_ROW_Scan(p, rest...); }
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)scan_in>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& R:c)for(auto& w:R)scan_in>>w;
// output
template<typename T>void MACRO_OUT(const T t) { std::cout << t; }
template<typename First, typename...Rest>void MACRO_OUT(const First first, const Rest...rest) { std::cout << first << " "; MACRO_OUT(rest...); }
#define OUT(...) MACRO_OUT(__VA_ARGS__);
#define FOUT(n, dist) std::cout<<std::fixed<<std::setprecision(n)<<(dist);
#define SOUT(n, c, dist) std::cout<<std::setw(n)<<std::setfill(c)<<(dist);
#define VOUT(v) for(size_t i = 0; i < v.size(); ++i) {OUT(v[i]);if(i+1<v.size()){SP}}
#define EOUT(...) do{ OUT(__VA_ARGS__)BR; exit(0); }while(0);
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
#define SHOW(dist) {std::cerr << #dist << "\t: " << (dist) << "\n";}
// utility
#define ALL(a) (a).begin(),(a).end()
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define REP(w, n) FOR(w, 0, n)
#define RFOR(w, a, n) for(int w=(n)-1;w>=(a);--w)
#define RREP(w, n) RFOR(w, 0, n)
template<class S, class T, class U> bool IN(S a, T x, U b) { return a <= x && x < b; }
template<class T> inline T CHMAX(T& a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T& a, const T b) { return a = (a > b) ? b : a; }
// test
template<class T> using V = std::vector<T>;
template<class T> using VV = V<V<T>>;

template<typename S, typename T>
std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p) {
	os << "(" << p.first << ", " << p.second << ")"; return os;
}
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
	os << "{";
	for (size_t i = 0; i < v.size(); ++i) os << v[i] << ((i + 1 < v.size()) ? ", " : ""); os << "}";
	return os;
}
template<typename T>
std::ostream & operator<<(std::ostream & os, const std::set<T> & v) {
	os << "{";
	for (auto it = v.cbegin();;) {
		os << *it; ++it;
		if (it == v.cend()) { os << "}"; break; }
		else { os << ", "; }
	}
	return os;
}
template<typename S, typename T>
std::ostream& operator<<(std::ostream & os, const std::map<S, T> & m) {
	os << "{";
	for (auto it = m.cbegin(); it != m.cend();) { os << it->first << ":" << it->second; ++it; os << (it == m.cend() ? "" : ", "); } os << "}";
	return os;
}
template<typename T>
std::ostream& operator<<(std::ostream & os, std::queue<T> q) {
	os << "<";
	while (!q.empty()) { os << q.front(); q.pop(); os << (q.empty() ? "<" : ", "); }
	return os;
}
template<typename T>
std::ostream& operator<<(std::ostream & os, std::stack<T> q) {
	os << ">";
	while (!q.empty()) { os << q.top(); q.pop(); os << (q.empty() ? "]" : ", "); }
	return os;
}
namespace std {
	template<typename S, typename T> class numeric_limits<pair<S, T>> {
	public:
		static constexpr pair<S, T> max() noexcept { return { numeric_limits<S>::max(), numeric_limits<T>::max() }; }
		static constexpr pair<S, T> lowest() noexcept { return { numeric_limits<S>::lowest(), numeric_limits<T>::lowest() }; }
	};
}

// type/const
using i64 = std::int_fast64_t;
using u64 = std::uint_fast64_t;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<i64, i64>;
using PAIRLL = std::pair<ll, ll>;
constexpr int INFINT = (1 << 30) - 1;                    // 1.07x10^ 9
constexpr int INFINT_LIM = (1LL << 31) - 1;              // 2.15x10^ 9
constexpr ll INFLL = 1LL << 60;                          // 1.15x10^18
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);  // 9.22x10^18
constexpr double EPS = 1e-6;
constexpr i64 MOD = 998244353;
constexpr double PI = 3.141592653589793238462643383279;
template<class T, size_t N> void FILL(T(&a)[N], const T & val) { for (auto& x : a) x = val; }
template<class ARY, size_t N, size_t M, class T> void FILL(ARY(&a)[N][M], const T & val) { for (auto& b : a) FILL(b, val); }
template<class T> void FILL(std::vector<T> & a, const T & val) { for (auto& x : a) x = val; }
template<class ARY, class T> void FILL(std::vector<std::vector<ARY>> & a, const T & val) { for (auto& b : a) FILL(b, val); }
// ------------>8---------

// ------------>8------------ SegmentTree ------------>8------------

namespace Monoid {
	template <class T> class sum {
	public:
		using value_type = T;
		inline static T operation(const T& a, const T& b) { return a + b; }
		inline static T identity() { return T(0); }
	};
	template <class T> class max {
	public:
		using value_type = T;
		inline static T operation(const T& a, const T& b) { return (a < b) ? b : a; }
		inline static T identity() { return std::numeric_limits<T>::lowest(); }
	};
	template <class T> class min {
	public:
		using value_type = T;
		inline static T operation(const T& a, const T& b) { return (a < b) ? a : b; }
		inline static T identity() { return std::numeric_limits<T>::max(); }
	};

	class MONOID {
	public:
		struct S { int x; };
		using value_type = S;
		inline static S operation(const S& l, const S& r) { return S{ l.x + r.x }; }
		inline static S identity() { return S{ 0 }; }
	};
}
template <class Monoid>
class SegmentTree {
private:
	using T = typename Monoid::value_type;
	int ARY_SIZE;
	std::vector<T> ary;

	void init(int n) {
		while (ARY_SIZE < n) ARY_SIZE <<= 1;
		ary.resize(ARY_SIZE << 1, Monoid::identity());
	}
public:
	SegmentTree(int n) : ARY_SIZE(1) { init(n); }
	SegmentTree(std::vector<T>& a) : ARY_SIZE(1) {
		init(a.size());
		std::copy(a.begin(), a.end(), ary.begin() + ARY_SIZE);
		for (int i = ARY_SIZE - 1; i >= 1; --i) {
			ary[i] = Monoid::operation(ary[i << 1], ary[(i << 1) + 1]);
		}
	}

	// -- a[i] = val;
	inline void update(int i, T val) {
		i += ARY_SIZE;
		ary[i] = val;
		while (i > 1) {
			i >>= 1;
			ary[i] = Monoid::operation(ary[i << 1], ary[(i << 1) + 1]);
		}
	}
	// -- a[i] += val;
	inline void add(int i, T val) {
		update(i, ary[i + ARY_SIZE] + val);
	}
	// -- [l, r)
	inline T query(int l, int r) {
		if (l >= r) return Monoid::identity();
		T vl = Monoid::identity(), vr = Monoid::identity();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) vl = Monoid::operation(vl, ary[l++]);
			if (r & 1) vr = Monoid::operation(ary[--r], vr);
		}
		return Monoid::operation(vl, vr);
	}
	T operator[](int i) { return ary[i + ARY_SIZE]; }

	template<class S>
	inline int max_right(int l, S f) {
		T v = Monoid::identity();
		std::vector<T> st({ v }); std::vector<int> id({ -1 });
		for (l += ARY_SIZE; ; l >>= 1) {
			if (l & 1) {
				v = Monoid::operation(v, ary[l]);
				st.emplace_back(v);
				id.emplace_back(l);
				if (f(v)) break;
				if ((l ^ (l + 1)) > l) break;
				++l;
			}
		}
		if (!f(v)) return ARY_SIZE;
		while (!st.empty()) {
			st.pop_back();
			int i = id.back(); id.pop_back();
			if (i == -1) return l;
			if (i >= ARY_SIZE) return i - ARY_SIZE;
			while (true) {
				i <<= 1;
				v = Monoid::operation(st.back(), ary[i]);
				if (i >= ARY_SIZE) return i - ARY_SIZE + !f(v);
				st.emplace_back(v); id.emplace_back(i);
				if (f(v)) break;
				++i;
			}
		}
		return -1;
	}

	void debugShow() {
		for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) std::cerr << ary[i] << " ";
		std::cerr << "\n";
	}
};
// ------------8<------------ SegmentTree ------------8<------------

signed main() {
	INIT;

	VAR(int, n, Q);
	VEC(int, a, n);

	a.emplace_back(INFINT);
	SegmentTree<Monoid::max<int>> st(a);
	REP(_, Q) {
		VAR(int, t, l, r);
		if (t == 1) {
			st.update(--l, r);
		}
		else if (t == 2) {
			OUT(st.query(--l, r))BR;
		}
		else {
			OUT(st.max_right(--l, [r](int x) {return x >= r; }) + 1)BR;
		}
	}

	return 0;
}