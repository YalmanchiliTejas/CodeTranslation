#ifdef __GNUC__ 
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
auto & inputdatastream = std::cin;
#define popcnt __builtin_popcountll
#define ctz __builtin_ctzll
#define clz64 __builtin_clzll
#else
std::ifstream inputdatastream;
unsigned int popcnt(unsigned long long a) {
	a = ((a >> 1) & 0x5555'5555'5555'5555ull) + (0x5555'5555'5555'5555ull & a);
	a = ((a >> 2) & 0x3333'3333'3333'3333ull) + (0x3333'3333'3333'3333ull & a);
	a = ((a >> 4) & 0x0f0f'0f0f'0f0f'0f0full) + (0x0f0f'0f0f'0f0f'0f0full & a);
	a = ((a >> 8) & 0x00ff'00ff'00ff'00ffull) + (0x00ff'00ff'00ff'00ffull & a);
	a = ((a >> 16) & 0x0000'ffff'0000'ffffull) + (0x0000'ffff'0000'ffffull & a);
	a = ((a >> 32) & 0x0000'0000'ffff'ffffull) + (0x0000'0000'ffff'ffffull & a);
	return static_cast<unsigned int>(a);
}
inline unsigned int ctz(unsigned long long x) { unsigned long r; _BitScanForward(&r, x); return r; }
inline unsigned int clz64(unsigned long long x) {
	unsigned long long r = 0, v = 1;
	while (v <= x)++r, v <<= 1;
	return r;
}
#endif
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/preprocessor.hpp>
#include <boost/mpl/int.hpp>
#include <boost/range.hpp>
#include <boost/icl/map.hpp>
#include <immintrin.h>
#include <iterator>
#include <boost/operators.hpp>
#include <boost/integer/common_factor_rt.hpp>
//#include <boost/integer/extended_euclidean.hpp>

template <typename T>using removeCVR = std::remove_reference_t< std::remove_cv_t<T> >;
//BOOST_PP_VARIADIC_ELEM_0

//#define rep(i, n) for(removeCVR<decltype(n)> i= 0;i<n;++i)

#define rep_main(i,start, n) for(removeCVR<decltype(n)> i= (start);i<(n);++i)
//なお、範囲外ポインタを生成しない用注意（未定義）
#define repd_main(i,l,n) for(removeCVR<decltype(n)> i= (n);i>(l)?(--i,true):false;)
#define REP_FOWORD(mainmacro, ...) mainmacro(	BOOST_PP_VARIADIC_ELEM (0,__VA_ARGS__),		\
								BOOST_PP_IF(BOOST_PP_EQUAL(2,BOOST_PP_VARIADIC_SIZE (__VA_ARGS__)),	\
									0,BOOST_PP_VARIADIC_ELEM (1,__VA_ARGS__)) ,	\
								BOOST_PP_VARIADIC_ELEM (BOOST_PP_DEC(BOOST_PP_VARIADIC_SIZE (__VA_ARGS__)),__VA_ARGS__)  )

//引数2なら0start、3引数なら開始Indexを受け取るrep
#define rep( ... ) REP_FOWORD(rep_main, __VA_ARGS__)
//引数2なら0start、3引数なら開始Indexを受け取るrep（ダウンカウント）
#define repd( ... ) REP_FOWORD(repd_main, __VA_ARGS__)
//#include <boost/numeric/ublas/blas.hpp>
//#include <boost/numeric/ublas/matrix.hpp>
//#include <boost/numeric/ublas/io.hpp>
//#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <type_traits>
using namespace std;
namespace renge = boost::range;

#define ALL(v) std::begin(v),std::end(v)


#define RALL(v) std::rbegin(v),std::rend(v)
namespace nazolib {
	using u6 = std::uint64_t;
	using s6 = std::int64_t;
	using u3 = std::uint32_t;
	using u1 = std::uint16_t;
	using s3 = std::int32_t;

	constexpr u6 moduloNo = 1'000'000'000 + 7; //' 1e9 + 7
	//constexpr u6 moduloNo = 998244353; //' prime


#define DEFVALUE1(r,type,name) type name;

#define DEFINIT0(r,type,name) in >> name;
#define DEFINIT1(r,size,name) name.resize(size);
#define DEFOSTREAM_FORDEBUG(r,type,name) out << name << " ";
#define DEFINITER template <typename T, typename In> void init(const T &, In &) {}
#define DEF_TYPEEXTSELECTOR(fnext,tpl)BOOST_PP_IF(BOOST_PP_TUPLE_ELEM(0, fnext)  ,BOOST_PP_TUPLE_ELEM(2, fnext),BOOST_PP_TUPLE_ELEM(0, tpl) )
#define DEFVALUEIMPL(r,fnext,tpl) BOOST_PP_LIST_FOR_EACH(BOOST_PP_TUPLE_ELEM(1,fnext),DEF_TYPEEXTSELECTOR(fnext,tpl), BOOST_PP_TUPLE_TO_LIST(BOOST_PP_TUPLE_POP_FRONT(tpl)))
#define DEFVALUES(expr) DEFIMPL(expr,0,DEFINIT0,0,_)
#define DEFIMPL(expr,deftypeindex,initcode,c,ext)																									\
			BOOST_PP_SEQ_FOR_EACH(DEFVALUEIMPL,(0,DEFVALUE1,_),BOOST_PP_VARIADIC_SEQ_TO_SEQ(expr))													\
			template <typename In> decltype(auto) init(boost::mpl::int_<deftypeindex> ,In & in){													\
				BOOST_PP_SEQ_FOR_EACH(DEFVALUEIMPL,(c,initcode,ext),BOOST_PP_VARIADIC_SEQ_TO_SEQ(expr));return in;}									\
			template <typename Out> decltype(auto) init(boost::mpl::int_<-deftypeindex-1>, Out & out) {												\
					BOOST_PP_SEQ_FOR_EACH(DEFVALUEIMPL, (c, DEFOSTREAM_FORDEBUG, ext), BOOST_PP_VARIADIC_SEQ_TO_SEQ(expr)); return out;}
#define DEFVECS(size,expr)  DEFIMPL(expr,1,DEFINIT1,1,size)
#define DEFSTRUCT(name,...) struct name{DEFINITER;__VA_ARGS__ ;friend std::istream & operator>>(std::istream & in,name & target){				\
		target.init(boost::mpl::int_<0> (),in);target.init(boost::mpl::int_<1>() ,in);return in;}												\
	friend std::ostream & operator<<(std::ostream & out, name & target) {																		\
			target.init(boost::mpl::int_<-1>(), out); return out;} }

	template <typename T>
	void initcalc(T & calc) {
		ios::sync_with_stdio(false); cin.tie(0);
		std::cout << std::fixed << std::setprecision(15);
#ifndef __GNUC__
		inputdatastream.open("inputdata.txt");
#endif
		calc.init(boost::mpl::int_<0>(), inputdatastream);
		calc.init(boost::mpl::int_<1>(), inputdatastream);
	}
	template <typename T>
	auto runcalc(T & c) ->std::enable_if_t<std::is_void<decltype(c.calc())>::value > {
		c.calc();
	}
	template <typename T>
	auto runcalc(T & c) ->std::enable_if_t<std::is_same<bool, decltype(c.calc())>::value > {
		const char * msg[] = { "No", "Yes" };
		std::cout << msg[c.calc()] << std::endl;
	}
	template <typename T>
	auto runcalc(T & c) ->std::enable_if_t<!(std::is_void<decltype(c.calc())>::value ||
		std::is_same<bool, decltype(c.calc())>::value) > {
		std::cout << c.calc() << std::endl;
	}
	template <typename T>
	struct invecT {
		decltype(auto) begin()const {
			return std::istream_iterator<T>(inputdatastream);
		}
		decltype(auto) end()const {
			return std::istream_iterator<T>();
		}
	};
	template <typename T>invecT<T> invec;
	//-------------------------------------------------------------------------------
	template <typename T>
	T read() {
		T tmp; inputdatastream >> tmp; return tmp;
	}
	template <typename T, std::size_t size>
	void read(std::array<T, size> &arr) {
		rep(i, size)inputdatastream >> arr[i];
	}

	template <typename T, std::size_t size>
	void read(T(&arr)[size]) {
		rep(i, size)inputdatastream >> arr[i];
	}
	template <typename T>
	void read(T * ptr, std::size_t size) {
		rep(i, size)inputdatastream >> ptr[i];
	}
	template <typename Cont>
	void read(Cont & cont, std::size_t size) {
		cont.resize(size);
		rep(i, size)inputdatastream >> cont[i];
	}
	template <typename Cont>
	void readidx(Cont & cont, std::size_t startidx, std::size_t size) {
		cont.resize(size);
		rep(i, size) {
			inputdatastream >> std::get<0>(cont[i]);
			std::get<1>(cont[i]) = i + startidx;
		}
	}
}using namespace nazolib;
namespace nightly {
	u6 pow2(u6 n) {
		if (n < 64)return (u6(1) << n) % moduloNo;
		else if (n == 64)return (u6(0) - moduloNo) % moduloNo;
		u6 tmp = pow2(n / 2);
		tmp = tmp * tmp;
		if (n & 1)tmp *= 2;
		return tmp % moduloNo;
	}
	template <u6 base>
	u6 powmodbase(u6 count) {
		u6 result = 1, st = 1;
		if (count == 0)return 1;
		if (count & 1) st = base;
		result = powmodbase<base>(count / 2);
		return (result* result) % moduloNo * st % moduloNo;
	}
	u6 powm(u6 base, u6 count) {
		u6 result = 1, st = 1;
		if (count == 0)return 1;
		if (count & 1) st = base;
		result = powm(base, count / 2);
		return (result* result) % moduloNo * st % moduloNo;
	}
	template <std::size_t dim, typename T>
	struct matcfg {};

	// TODO:トレイトなりCRTPなり使って式テンプレート使って・・・
	// *=は、 rhs*=lhsとなっているので注意
	template <std::size_t dim, typename T = u6>//bool istrans=true;
	struct modulomatrix { // : public boost::multipliable1<modulomatrix<dim,T> > {
		array<array<T, dim>, dim> buf;
		friend modulomatrix operator*(const modulomatrix & lhs, const modulomatrix & rhs) {
			modulomatrix tmp{};
			rep(i, dim) {
				rep(j, dim) {
					rep(k, dim) {
						tmp.buf[i][j] = (tmp.buf[i][j] + rhs.buf[k][j] * lhs.buf[i][k]) % moduloNo;;
					}
				}
			}
			return tmp;
		}
		modulomatrix toid()const {
			modulomatrix tmp{};
			rep(i, dim) { tmp.buf[i][i] = 1; }
			return tmp;
		}
		modulomatrix & operator*=(const modulomatrix & lhs) {
			//*this = lhs * *this;
			return *this = lhs * *this;
		}
		friend std::ostream & operator<<(std::ostream & out, const modulomatrix & x) {
			out << "{"; for (const auto & w : x.buf) {
				cout << "(";
				for (auto h : w)cout << h << " ";
				cout << ")";
			}
			out << "}" << endl;
			return out;
		}
	};
	template <std::size_t dim, typename T>
	modulomatrix<dim, T> powm(const modulomatrix<dim, T> & m, u6 count) {
		if (count == 0)return m.toid(); //count==
		auto r = powm(m, count / 2);
		if (count & 1)return r * r*m;
		else return r * r;
	}

	template <std::size_t dim, typename T = u6>
	struct modulovector { // : public boost::multipliable1<modulovector<dim, T> > {
		array<T, dim> buf;
		//modulovector() = default;
		//modulovector(std::initializer_list<T> i) :buf( i ) {}
		//friend struct boost::multipliable1<modulovector<dim, T> >;

		template <typename T2>
		friend modulovector operator*(const modulomatrix<dim, T2> & lhs, const modulovector & rhs) {
			modulovector tmp{};
			rep(i, dim) {
				rep(j, dim) {
					tmp.buf[i] = (tmp.buf[i] + rhs.buf[j] * lhs.buf[i][j]) % moduloNo;
				}
			}
			return tmp;
		}
		template <typename T2>
		modulovector & operator*=(const modulomatrix<dim, T2> & lhs) {
			return *this = lhs * *this;
		}
		friend std::ostream & operator<<(std::ostream & out, const modulovector & x) {
			out << "("; for (auto val : x.buf)cout << val << " ";
			out << ")" << endl;
			return out;
		}
	};
	//区間そのものがほしいケースも対応できた方がいいかも
	//必要なら木そのものに入れるかな
	template <typename T, typename Fn>struct segtree {
		T invoidval;
		Fn fn;
		std::vector<T> buf;
		segtree() = default;
		explicit segtree(std::size_t s, Fn fn_, T invoid) :invoidval(invoid), buf(s * 2 - 1, invoidval), fn(fn_) {
		}
		void update1(std::size_t index, const T & val) {
			index += buf.size() / 2;
			buf[index] = val;
			while (index) {
				index = (index - 1) / 2;
				buf[index] = fn(buf[index * 2 + 1], buf[index * 2 + 2]);
			}
		}
		//クエリー閉区間
		T loopup(std::size_t l, std::size_t r, std::size_t index = 0, std::size_t li = 0, std::size_t ri = 0) {
			if (index == 0)ri = (buf.size() + 1) / 2;
			if (ri <= l || r <= li)return invoidval;
			if (l <= li || ri <= r)return buf[index];
			return fn(loopup(l, r, 2 * index + 1, li, (li + ri) / 2),
				loopup(l, r, 2 * index + 2, (li + ri) / 2, ri));
		}
	};
	template <typename T, typename Fn>
	auto gensegtree(Fn fn, std::size_t n, T invoidval = -1) {
		std::size_t n2 = 1;
		while (n2 < n)n2 <<= 1;
		return segtree<T, Fn>(n2, fn, invoidval);
	}
	long long extGCD(long long a, long long b, long long &x, long long &y) {
		if (b == 0) {
			x = 1;
			y = 0;
			return a;
		}
		long long d = extGCD(b, a%b, y, x);
		y -= a / b * x;
		return d;
	}
	template <bool isdynamic>
	struct modtablebase {
		u6 static constexpr moduloNo = ::moduloNo;
		void baseinit(u6) {}
	};
	template <>
	struct modtablebase<true> {
		u6 moduloNo;
		void baseinit(u6 val) { moduloNo = val; }
	};

	template <u6 maxsize, bool isdynamic = false>
	struct modtable :public modtablebase <isdynamic> {
		u6 fact[maxsize];
		u6 invfact[maxsize];
		u6 inv[maxsize];
		using modtablebase <isdynamic>::moduloNo;
		modtable() {
			autoinit<>();
		}
		void init(u6 moduloNo_) {
			this->baseinit(moduloNo_);
			fact[0] = 1;
			fact[1] = 1;
			inv[1] = 1;
			invfact[1] = 1;
			invfact[0] = 1;
			auto maxsize_ = min(maxsize, moduloNo);
			for (u6 i = 2; i < maxsize_; ++i) {
				fact[i] = (i*fact[i - 1]) % moduloNo;
				inv[i] = moduloNo - inv[moduloNo%i] * (moduloNo / i) % moduloNo;
				invfact[i] = invfact[i - 1] * inv[i] % moduloNo;
			}
			//cout << moduloNo << endl;
		}

		u6 comb(u6 n, u6 k)const {
			return fact[n] * invfact[k] % moduloNo * invfact[n - k] % moduloNo;
		}
	private:
		template <bool dummy = isdynamic> typename std::enable_if<dummy>::type autoinit() {}
		template <bool dummy = isdynamic> typename std::enable_if<!dummy>::type autoinit() {
			init(0);
		}
	};
	/*
	//isdynamicとかを引数に追加して共通化できるならしたほうがいいな
	template <u6 maxsize>
	struct modtabledynamic {
		u6 fact[maxsize];
		u6 invfact[maxsize];
		u6 inv[maxsize];
		u6 moduloNo;
		void init(u6 moduloNo_){
			moduloNo = moduloNo_;
			fact[0] = 1;
			fact[1] = 1;
			inv[1] = 1;
			invfact[1] = 1;
			invfact[0] = 1;
			auto maxsize_ = min(maxsize, moduloNo);
			for (u6 i = 2; i < maxsize_; ++i) {
				fact[i] = (i*fact[i - 1]) % moduloNo;
				inv[i] = moduloNo - inv[moduloNo%i] * (moduloNo / i) % moduloNo;
				invfact[i] = invfact[i - 1] * inv[i] % moduloNo;
			}
		}
		u6 comb(u6 n, u6 k)const {
			return fact[n] * invfact[k] % moduloNo * invfact[n - k] % moduloNo;
		}
	};*/
	template <typename T = s6>
	struct midianset {
		multiset<T> s;
		typename multiset<T>::iterator mid;
		s6 sums[2] = {};
		auto size()const { return s.size(); }
		void ajust(unsigned cond, T val) {
			static_assert((5 > 3) == 1, "***true!=1***");
			sums[!cond] += val;
			if ((s.size() & 1u) != cond) {
				sums[cond] += *mid;
				cond ? --mid : ++mid;
				sums[!cond] -= *mid;
			}
		}
		void insert(T val) {
			if (s.size() == 0) mid = s.insert(val);
			else {
				s.insert(val);
				ajust(val < *mid, val);
			}
		}
		auto sum() const noexcept {
			return tuple<T, T, T>(sums[0], *mid, sums[1]);
		}
	};


}
using namespace nightly;
//using namespace nazolib;
/*******************************************************************************/
//constexpr u6 shiftsize = 10+5;
//constexpr u6 bufsize = 1 << shiftsize;

//margeしたりinsしたりするとき用のコールバックも必要な感じかな
//そのときに追加データも参照できるべきな感じ。
//タプルにして先頭を・・・いや、pairかな
//・・・listのiteratorかな
//データを外部に持つかどうかも入れるのもありだが・・・下手するとかえってコスト高になるか
//（構造体のサイズ>ポインタのサイズ、で、十分にでかくないとマイナス）
//制約：Tplの先頭要素はunifindのインデックスでなければならない(std::arrayでも可)
template <typename Tpl, std::size_t maxsize, bool isZeronodeCount, typename createnodeFn>
struct unionfind {
	using T = std::remove_cv_t< std::remove_reference_t<decltype(std::get<0>(std::declval<Tpl>()))> >;
	Tpl buf[maxsize];
	//T count=0;
	/*
	void resize(std::size_t n) {
		assert(v.size() == 0); v.resize(n + 1);
		if (isZeronodeCount)count = v.size() - 1;
		else count = 0;
	}*/
	createnodeFn createnodefn;
	constexpr unionfind() = default;
	constexpr explicit unionfind(createnodeFn fn) :createnodefn{ fn } {}
	class findResult {
		friend class unifind; friend class findResultVec;
		T index_;
		std::vector<T> updatenode;
	public:
		T index()const { return index_; }
		bool isnewnode()const { return index == 0; }
		explicit operator bool()const { return isnewnode(); }
	};
	struct findResultVec {
		unionfind * punifind;
		using Cont = std::vector<std::tuple<T, std::vector<T>, bool > >;
		struct proxy {
			T val;
			bool newnode;
			operator T()const { return val; }
			explicit operator bool()const { return !newnode; }
			friend bool operator==(const proxy & l, const proxy & r) {
				return l.val == r.val;
			}
			friend bool operator!=(const proxy & l, const proxy & r) {
				return l.val != r.val;
			}
		};
		Cont st;
		void merge() {
			for (auto & cont : st)merge(cont, get<0>(cont));
			st.clear();
		}
		void merge(T nodeNo) {
			for (auto & cont : st)merge(cont, nodeNo);
			st.clear();
		}
		void merge(typename Cont::reference cont, T nodeNo) {
			get<0>(punifind->buf[get<0>(cont)]) = nodeNo;
			for (auto & v2 : get<1>(cont)) {
				get<0>(punifind->buf[v2]) = nodeNo;
				//v2 = nodeNo;
				//cont.clear();
			}
		}
		proxy operator[](std::size_t index) const {
			return proxy{ get<0>(st[index]),get<2>(st[index]) };
		}
		//explicit findResult(unionfind * p) :punifind{ p } {}
	private:
	};
	template <typename Fn, typename U, typename ...R>
	void findsimpl(Fn fn, findResultVec & st, const U & indexortpl, const R &... r) {
		st.st[st.st.size() - 1 - sizeof...(r)] = getroot(indexortpl);
		findsimpl(fn, st, r...);
	}
	template <typename Fn>
	void findsimpl(Fn fn, findResultVec & st) {
		fn(st);
		st.merge();
	}
	template <typename Fn, typename ...R>
	void finds(Fn fn, const R & ...r) {

		findResultVec tmp{ this };
		//tmp.punifind= this;
		tmp.st.resize(sizeof...(R));
		findsimpl(fn, tmp, r...);
	}
	/*
	template <bool ismerge>
	bool find(T l, T r) {//可変長引数とかも選択肢？
		auto ll = getroot(l);
		auto rr = getroot(r);
		auto update = [this](const auto & updateindex, T minval) {
			for (auto i : updateindex)v[i] = minval;
		};
		if (ismerge) {
			std::pair<T, T> t = std::minmax(ll.first, rr.first);
			if (ll.first != rr.first) {
				--count;
				v[t.second] = t.first;
			}
			update(ll.second, t.first);
			update(rr.second, t.first);
		}
		else {
			update(ll.second, ll.first);
			update(rr.second, rr.first);
		}
		return ll.first == rr.first;
	}*/
private:
	std::tuple<T, std::vector<T>, bool > getroot(T node) {
		std::tuple<T, std::vector<T>, bool > result{ node,{},false };
		if (!get<0>(buf[node])) {
			buf[node] = createnodefn(node);
			//++count;
			std::get<2>(result) = true;
		}
		while (get<0>(buf[node]) != node) {//先頭も追加しておいた方が便利そう
			get<1>(result).push_back(node);
			node = get<0>(buf[node]);
		}
		std::get<0>(result) = node;
		return result;
	}
};
template <typename Tpl, std::size_t maxsize, bool isZeronodeCount = false, typename Fn>
constexpr auto make_unifind(Fn fn) {
	return unionfind<Tpl, maxsize, isZeronodeCount, Fn>{fn};
}
//static auto uni = make_unifind<std::array<u3, 3>, (1<<18)>([](u3 index) {return std::array<u3, 3>{ index, 1, 1 }; });
DEFSTRUCT(datatype, DEFVALUES(///////////////////////////////////////////////////////
(string, a)
)///////////////////////////////////////////////////////
);
/*
namespace dfsnightry {
	struct Node {
		vector<pair<u3, s3> > next;
		vector<pair<u3, s3> > prev;
		u3 updatecount;
		u3 prevroute;
		s3 diff;
		s3 prevweight;
	};
	Node nodes[2501];
	template <typename MenPtr>
	void markgoal(u3 index, MenPtr ptr, u3 count) {
		if (nodes[index].updatecount != count - 1)return;
		nodes[index].updatecount = count;
		for (auto v : nodes[index].*ptr) {
			markgoal(v.first, ptr, count);
		}
	}
	void removeedge(u3 index) {
		auto & node = nodes[index];
		u3 erasecount = 0;
		for (u3 i = 0; i + erasecount < node.next.size(); ++i) {
			while (nodes[node.next[i].first].updatecount <= 1) {
				if (i + erasecount >= node.next.size())break;
				++erasecount;
				swap(node.next[i], node.next[node.next.size() - erasecount]);
			}
			if (i + erasecount < node.next.size() && nodes[node.next[i].first].updatecount == 2) {
				nodes[node.next[i].first].updatecount = 3;
				removeedge(node.next[i].first);
			}
		}
		node.next.resize(node.next.size() - erasecount);
		//node.next.erase(node.next.end() - erasecount, node.next.end());
	}
}*/
//double resulttable[8][8];

/*
	a = ((a >> 1) & 0x5555'5555'5555'5555ull) + (0x5555'5555'5555'5555ull & a);
	a = ((a >> 2) & 0x3333'3333'3333'3333ull) + (0x3333'3333'3333'3333ull & a);
	a = ((a >> 4) & 0x0f0f'0f0f'0f0f'0f0full) + (0x0f0f'0f0f'0f0f'0f0full & a);
	a = ((a >> 8) & 0x00ff'00ff'00ff'00ffull) + (0x00ff'00ff'00ff'00ffull & a);
	a = ((a >> 16) & 0x0000'ffff'0000'ffffull) + (0x0000'ffff'0000'ffffull & a);
	a = ((a >> 32) & 0x0000'0000'ffff'ffffull) + (0x0000'0000'ffff'ffffull & a);
*/
/*素数表や分解等を用意したほうが良さそうなのでabc152eのコードを元に作っておきたいところ

*/
//modtable<u6(1e6 + 1)> tbl;

struct Calc {
	DEFINITER;
	DEFVALUES(//////////////////////////////////////////////////
		(string, S)
	);///////////////////////////////////////////////////////
	auto calc() {
		return any_of(ALL(S), [&, this](auto c) {return c != S.front(); });
	}

	/*******************************************************************************/
};

int main() {
	static Calc calc;
	try {
		initcalc(calc); runcalc(calc);
	}
	catch (const char * msg) {
		cout << msg << endl;
	}
	return 0;
}

