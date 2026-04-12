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

// input
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest& ...rest) { std::cin >> first; MACRO_VAR_Scan(rest...); }
#define VEC_ROW(type, n, ...)std::vector<type> __VA_ARGS__;MACRO_VEC_ROW_Init(n, __VA_ARGS__); for(int w_=0; w_<n; ++w_){MACRO_VEC_ROW_Scan(w_, __VA_ARGS__);}
template<typename T> void MACRO_VEC_ROW_Init(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Init(int n, First& first, Rest& ...rest) { first.resize(n); MACRO_VEC_ROW_Init(n, rest...); }
template<typename T> void MACRO_VEC_ROW_Scan(int p, T& t) { std::cin >> t[p]; }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Scan(int p, First& first, Rest& ...rest) { std::cin >> first[p]; MACRO_VEC_ROW_Scan(p, rest...); }
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& R:c)for(auto& w:R)std::cin>>w;
// output
template<typename T>void MACRO_OUT(const T t) { std::cout << t; }
template<typename First, typename...Rest>void MACRO_OUT(const First first, const Rest...rest) { std::cout << first << " "; MACRO_OUT(rest...); }
#define OUT(...) MACRO_OUT(__VA_ARGS__);
#define FOUT(n, dist) std::cout<<std::fixed<<std::setprecision(n)<<(dist);
#define SOUT(n, c, dist) std::cout<<std::setw(n)<<std::setfill(c)<<(dist);
#define EOUT(...) { OUT(__VA_ARGS__)BR; exit(0); }
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
#define SHOW(dist) {std::cerr << #dist << "\t: " << (dist) << "\n";}
#define SHOWVECTOR(v) {std::cerr << #v << "\t: ";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWQUEUE(a) {auto tmp(a);std::cerr << #a << "\t: ";while(!tmp.empty()){std::cerr << tmp.front() << " ";tmp.pop();}std::cerr << "\n";}
#define SHOWSTACK(a) {auto tmp(a);std::cerr << #a << "\t: ";while(!tmp.empty()){std::cerr << tmp.top() << " ";tmp.pop();}std::cerr << "\n";}
// utility
#define ALL(a) (a).begin(),(a).end()
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define REP(w, n) FOR(w, 0, n)
#define RFOR(w, a, n) for(int w=(n)-1;w>=(a);--w)
#define RREP(w, n) RFOR(w, 0, n)
template<class S, class T, class U> bool IN(S a, T x, U b) { return a <= x && x < b; }
//#define IN(a, x, b) (a<=x && x<b)
template<class T> inline T CHMAX(T& a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T& a, const T b) { return a = (a > b) ? b : a; }
// test
template<class T> using V = std::vector<T>;
template<class T> using VV = V<V<T>>;

template<typename S, typename T>
std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
	os << "(" << p.first << ", " << p.second << ")"; return os;
}

// type/const
using i64 = std::int_fast64_t;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<i64, i64>;
using PAIRLL = std::pair<ll, ll>;
constexpr i64 INFINT = (1 << 30) - 1;                    // 1.07x10^ 9
constexpr i64 INFINT_LIM = (1LL << 31) - 1;              // 2.15x10^ 9
constexpr ll INFLL = 1LL << 60;                          // 1.15x10^18
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);  // 9.22x10^18
constexpr double eps = 1e-6;
constexpr i64 MOD = 1000000007;
constexpr double PI = 3.141592653589793238462643383279;
template<class T, size_t N> void FILL(T(&a)[N], const T & val) { for (auto& x : a) x = val; }
template<class ARY, size_t N, size_t M, class T> void FILL(ARY(&a)[N][M], const T & val) { for (auto& b : a) FILL(b, val); }
template<class T> void FILL(std::vector<T> & a, const T & val) { for (auto& x : a) x = val; }
template<class ARY, class T> void FILL(std::vector<std::vector<ARY>> & a, const T & val) { for (auto& b : a) FILL(b, val); }
// ------------>8---------

// USE i64 !

// ------------>8---------- LazySegmentTree ---------->8------------
namespace MonoidOfValue {
	template <class T> class sum {
	public:
		using value_type = T;
		inline static T op(const T& a, const T& b) { return a + b; }
		inline static value_type id() { return T(0); }
	};
	template <class T> class max {
	public:
		using value_type = T;
		inline static T op(const T& a, const T& b) { return (a < b) ? b : a; }
		inline static T id() { return std::numeric_limits<T>::lowest(); }
	};
	template <class T> class min {
	public:
		using value_type = T;
		inline static T op(const T& a, const T& b) { return (a < b) ? a : b; }
		inline static T id() { return std::numeric_limits<T>::max(); }
	};

	class MONOID {
	public:
		struct S { int x; };
		using T = S;
		using value_type = T;
		inline static T op(const T& l, const T& r) { return S{ 0 }; }
		inline static T id() { return S{ 0 }; }
	};
}
namespace MonoidOfOperator {
	template <class T> class add {
	public:
		using value_type = T;
		inline static T op(const T& a, const T& b) { return a + b; }
		inline static T id() { return T(0); }
	};
	template <class T> class upd {
	public:
		using value_type = T;
		inline static T op(const T& a, const T& b) { return b; }
		inline static T id() { return T(0); }
	};
}
namespace ApplyOperator {
	template <class T1, class T2> class RSQRAQ {
	public:
		inline static T1 op(const T1& a, const T2& b, int w) { return a + b * w; }
	};
	template <class T1, class T2> class RSQRUQ {
	public:
		inline static T1 op(const T1& a, const T2& b, int w) { return b * w; }
	};
	template <class T1, class T2> class RMQRAQ {
	public:
		inline static T1 op(const T1& a, const T2& b, int w) { return a + b; }
	};
	template <class T1, class T2> class RMQRUQ {
	public:
		inline static T1 op(const T1& a, const T2& b, int w) { return b; }
	};
}
template<class MonoidOfValue, class MonoidOfOperator, template<class, class> class ApplyOperator>
class LazySegmentTree {
private:
	using ValueType = typename MonoidOfValue::value_type;
	using OperatorType = typename MonoidOfOperator::value_type;
	using Applier = ApplyOperator<ValueType, OperatorType>;
	std::vector<ValueType> seg;
	std::vector<OperatorType> laz;
	std::vector<bool> isUpdated;
	int HEIGHT;
	int ARY_SIZE;

	void push(int k, int w) {
		if (!isUpdated[k]) {
			seg[k] = Applier::op(seg[k], laz[k], w);
			if (w > 1) {
				laz[(k << 1) + 0] = MonoidOfOperator::op(laz[(k << 1) + 0], laz[k]);
				laz[(k << 1) + 1] = MonoidOfOperator::op(laz[(k << 1) + 1], laz[k]);
				isUpdated[(k << 1) + 0] = false;
				isUpdated[(k << 1) + 1] = false;
			}
			isUpdated[k] = true;
			laz[k] = MonoidOfOperator::id();
		}
	}
	void update(int k, int w) {
		push(k, w);
		if (k < ARY_SIZE) {
			push((k << 1) + 0, w >> 1);
			push((k << 1) + 1, w >> 1);
			seg[k] = MonoidOfValue::op(seg[(k << 1) + 0], seg[(k << 1) + 1]);
		}
	}
public:
	LazySegmentTree(int n) {
		init(n);
	}
	LazySegmentTree(const std::vector<ValueType> & a) {
		init(a.size());
		std::copy(std::begin(a), std::end(a), std::begin(seg) + ARY_SIZE);
		for (int k = ARY_SIZE - 1; k > 0; --k) seg[k] = MonoidOfValue::op(seg[(k << 1) + 0], seg[(k << 1) + 1]);
	}
	void init(int n) {
		HEIGHT = 0;
		while ((1 << HEIGHT) < n) ++HEIGHT;
		ARY_SIZE = 1 << HEIGHT;
		seg.resize(ARY_SIZE << 1, MonoidOfValue::id());
		laz.resize(ARY_SIZE << 1, MonoidOfOperator::id());
		isUpdated.resize(ARY_SIZE << 1, true);
	}
	// ## update [l, r) with v
	void update(int l, int r, OperatorType v) {
		l += ARY_SIZE; r += ARY_SIZE;
		int L = l, R = r - 1;
		for (int i = HEIGHT; i >= 0; --i) push(L >> i, 1 << i), push(R >> i, 1 << i);
		while (l < r) {
			if (l & 1) laz[l] = MonoidOfOperator::op(laz[l], v), isUpdated[l] = false, ++l;
			if (r & 1) --r, laz[r] = MonoidOfOperator::op(laz[r], v), isUpdated[r] = false;
			l >>= 1; r >>= 1;
		}
		for (int i = 1; i <= HEIGHT; ++i) {
			push(L >> i, 1 << i), push(R >> i, 1 << i);
			update(L >> i, 1 << i), update(R >> i, 1 << i);
		}
	}
	// ## return SUM/MAX/MIN in [l, r)
	ValueType query(int l, int r) {
		l += ARY_SIZE; r += ARY_SIZE - 1;
		for (int i = HEIGHT; i >= 0; --i) push(l >> i, 1 << i), push(r >> i, 1 << i);
		++r;
		ValueType vl = MonoidOfValue::id(), vr = MonoidOfValue::id();
		int w = 1;
		while (l < r) {
			if (l & 1) update(l, w), vl = MonoidOfValue::op(vl, seg[l]), ++l;
			if (r & 1) --r, update(r, w), vr = MonoidOfValue::op(seg[r], vr);
			l >>= 1; r >>= 1; w <<= 1;
		}
		return MonoidOfValue::op(vl, vr);
	}
};
// ------------>8---------- LazySegmentTree ---------->8------------

signed main() {
	INIT;

	VAR(i64, n);
	VEC(i64, a, n);

	VV<i64> b(2);
	REP(i, n) b[i % 2].emplace_back(a[i]);

	i64 ans = -INFLL;

	if (n % 2 == 1) {
		V<i64> tmp(n / 2, 0);
		LazySegmentTree<MonoidOfValue::max<i64>, MonoidOfOperator::add<i64>, ApplyOperator::RMQRAQ> lst(tmp);
		tmp.resize(0);

		i64 sumL = 0, sumR = 0;
		REP(i, n / 2) sumL += b[0][i];
		RREP(i, n / 2) {
			CHMAX(ans, sumL + lst.query(0, n / 2 - i));
			sumL -= b[0][i];
			sumR += b[0][i + 1];
			lst.update(0, n / 2 - i, b[1][i]);
			lst.update(n / 2 - i, n / 2 - i + 1, sumR);
		}

		a.erase(a.begin());
		b[0].erase(b[0].begin());
		--n;
	}

	VV<i64> c(2, V<i64>(n / 2 + 1, 0));
	REP(i, n / 2) c[0][i + 1] = c[0][i] + b[0][i];
	RREP(i, n / 2) c[1][i] = c[1][i + 1] + b[1][i];
	REP(i, n / 2 + 1) CHMAX(ans, c[0][i] + c[1][i]);

	OUT(ans)BR;

	return 0;
}