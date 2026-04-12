#ifdef __GNUC__ 
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
auto & inputdatastream = std::cin;
#define popcnt __builtin_popcountll
#else
std::ifstream inputdatastream;
unsigned int popcnt(unsigned long long a) {
	a = (a >> 1) & 0x5555'5555'5555'5555ull + 0x5555'5555'5555'5555ull & a;
	a = (a >> 2) & 0x3333'3333'3333'3333ull + 0x3333'3333'3333'3333ull & a;
	a = (a >> 4) & 0x0f0f'0f0f'0f0f'0f0full + 0x0f0f'0f0f'0f0f'0f0full & a;
	a = (a >> 8) + a;
	a = (a >> 16) & 0x0000'ffff'0000'ffffull + 0x0000'ffff'0000'ffffull & a;
	a = (a >> 32) & 0x0000'0000'ffff'ffffull + 0x0000'0000'ffff'ffffull & a;
	return static_cast<unsigned int>(a);
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
//#include <boost/numeric/ublas/blas.hpp>
//#include <boost/numeric/ublas/matrix.hpp>
//#include <boost/numeric/ublas/io.hpp>
//#include <boost/numeric/ublas/matrix_proxy.hpp>
using namespace std;
namespace renge = boost::range;

#define ALL(v) std::begin(v),std::end(v)


#define RALL(v) std::rbegin(v),std::rend(v)
using u6 = std::uint64_t;
using s6 = std::int64_t;
using u3 = std::uint32_t;
using s3 = std::int32_t;

constexpr u6 moduloNo = 1'000'000'000 + 7; //' 1e9 + 7
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
auto runcalc(T & c) ->std::enable_if_t<!std::is_void<decltype(c.calc())>::value > {
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

namespace nightly {

	template <typename T, bool isZeronodeCount = true>
	struct unionfind {
		std::vector<T> v;
		T count;
		void resize(std::size_t n) {
			assert(v.size() == 0); v.resize(n + 1);
			if (isZeronodeCount)count = v.size() - 1;
			else count = 0;
		}
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
		}
	private:
		std::pair<T, std::vector<T> > getroot(T node) {
			std::pair<T, std::vector<T> > result;
			if (!v[node])v[node] = node;
			while (v[node] != node) {
				result.second.push_back(node);
				node = v[node];
			}
			result.first = node;
			return result;
		}
	};
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


}using namespace nightly;
/*******************************************************************************/
//constexpr u6 shiftsize = 10+5;
//constexpr u6 bufsize = 1 << shiftsize;

DEFSTRUCT(datatype, DEFVALUES(///////////////////////////////////////////////////////
(string , a)
)///////////////////////////////////////////////////////
);
namespace mp = boost::multiprecision;
//using mp6=mp::number<mp::cpp_int_backend<64, 64, mp::unsigned_magnitude, mp::unchecked>>;
//typedef decltype (mulmm<250>::mul(t1, t2))) typea;
struct Calc {
	DEFINITER;
	DEFVALUES(//////////////////////////////////////////////////
		(mp::cpp_int, N,M,K)
	);///////////////////////////////////////////////////////
	template <typename T>
	mp::cpp_int  sumd(const T & width) {
		// sum d*(M-d) = d*M-d**2
      	return (width * (width + 1)*(3 * width - (width * 2 + 1))/6 )% moduloNo;

	}
	auto  calc() {
		mp::cpp_int kmax = K - 2;
		mp::cpp_int cellcount = N * M - 2;
		mp::cpp_int r = 1,factor=1,divval=1;
		if (cellcount >= 2) {
          	mp::cpp_int t=cellcount - kmax;
			kmax=min(kmax,t);
			for (mp::cpp_int k = 1; k <= kmax; ++k) {
				factor *= cellcount;
				divval *= k;
				--cellcount;
			}
			r = factor / divval % moduloNo;
		}
		mp::cpp_int result =  r * (M*M*sumd(N) + N*N*sumd(M)) % moduloNo;
		return result;
	}
	/*******************************************************************************/
};

int main() {
	static Calc calc;
	initcalc(calc); runcalc(calc);
}
