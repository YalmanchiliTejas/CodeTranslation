#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<deque>
#include<utility>
#include<tuple>
#include<bitset>
#include<complex>
// #include<ratio>
#include<algorithm>
#include<numeric>
// #include<limits>
// #include<chrono>
// #include<random>
// #include<regex>
// #include<functional>
#include<boost/multiprecision/cpp_int.hpp>
// <iostream>
using std::cin;
using std::cout;
using std::clog;
using std::cerr;
using std::endl;
// <ios>
using std::ios_base;
// <string>
using std::string;
using std::to_string;
using std::stoi;
using std::stol;
// <vector>
using std::vector;
// <map>
using std::map;
// <set>
using std::set;
// <queue>
using std::priority_queue;
using std::queue;
// <stack>
using std::stack;
// <deque>
using std::deque;
// <utility>
using std::pair;
// <tuple>
using std::tuple;
// <bitset>
using std::bitset;
// <complex>
using std::complex;
using std::real;
using std::imag;
using std::sin;
using std::cos;
using std::tan;
using std::asin;
using std::acos;
using std::atan;
using std::sinh;
using std::cosh;
using std::tanh;
using std::asinh;
using std::acosh;
using std::atanh;
using std::abs;
using std::pow;
using std::sqrt;
using std::exp;
using std::log;
using std::log10;
using std::polar;
using std::norm;
// <ratio>
// using std::ratio;
// <algorithm>
using std::all_of;
using std::any_of;
using std::none_of;
using std::find;
using std::count;
using std::swap;
using std::fill;
using std::unique;
using std::reverse;
using std::rotate;
using std::shuffle;
using std::sort;
using std::stable_sort;
using std::partial_sort;
using std::nth_element;
using std::lower_bound;
using std::upper_bound;
using std::equal_range;
using std::binary_search;
using std::set_union;
using std::set_intersection;
using std::set_difference;
using std::min;
using std::max;
using std::minmax; // value
using std::min_element;
using std::max_element;
using std::minmax_element; // pointer
using std::next_permutation;
using std::prev_permutation;
// <numeric>
using std::accumulate;
// <limits>
// using std::numeric_limits;
// <chrono>
// using std::chrono::system_clock;
// <random>
// using std::mt19937_64;
// <regex>
// using std::regex_match;
// <functional>
// using std::function;
// <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using ll=long long;
using ld=long double;
using ull=unsigned long long;
// using vi=vector<int>;
// using vll=vector<ll>;
// using vs=vector<string>;
// using msi=map<string,int>;
// using si=set<int>;
// using ss=set<string>;
// using pii=pair<int,int>;
// using tiii=tuple<int,int,int>;
// using pqi=priority_queue<int>;
// using pqpii=priority_queue<pii>;
// using pqtiii=priority_queue<tiii>;
#define BEGIN ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define END return EXIT_SUCCESS
#define up(I,A,B) for(auto I=(A);I<=(B);++I)
#define dw(I,A,B) for(auto I=(A);I>=(B);--I)
#define rep(I,N) up(I,0,N-1)
#define all(C) (C).begin(),(C).end()
#define rall(C) (C).rbegin(),(C).rend()
#define ft first
#define sd second
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define rs resize
#define np next_permutation
#define pp prev_permutation
#define rev reverse
template<class T>inline void                                      in(T &p){cin>>p;}
template<class T1,class T2>inline void                            in(T1 &p1,T2 &p2){cin>>p1>>p2;}
template<class T1,class T2,class T3>inline void                   in(T1 &p1,T2 &p2,T3 &p3){cin>>p1>>p2>>p3;}
template<class T1,class T2,class T3,class T4>inline void          in(T1 &p1,T2 &p2,T3 &p3,T4 &p4){cin>>p1>>p2>>p3>>p4;}
template<class T1,class T2,class T3,class T4,class T5>inline void in(T1 &p1,T2 &p2,T3 &p3,T4 &p4,T5 &p5){cin>>p1>>p2>>p3>>p4>>p5;}
template<class T>inline void                                      ins(T &p){for_each(all(p),in<decltype(p[0])>);}
template<class T>inline void                             out(T p){cout<<p<<"\n";}
template<class T1,class T2>inline void                   out(T1 p1,T2 p2){cout<<p1<<" "<<p2<<"\n";}
template<class T1,class T2,class T3>inline void          out(T1 p1,T2 p2,T3 p3){cout<<p1<<" "<<p2<<" "<<p3<<"\n";}
template<class T1,class T2,class T3,class T4>inline void out(T1 p1,T2 p2,T3 p3,T4 p4){cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<"\n";}
inline void                                              out(ld p){printf("%.12Lf\n",p);}
template<class T>inline void outml(T p){for_each(all(p),out<decltype(p[0])>);}//ml=multi line
template<class T>inline void outol(T V){auto n=V.size();rep(i,n)cout<<V[i]<<" \n"[i==n-1];}//ol=one line
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
ll N,mod=1e9+7;
cpp_int ans;
inline void solve(void){
  in(N);
  vector<cpp_int>A(N);
  ins(A);
  vector<cpp_int>s(N+1);
  rep(i,N)s[i+1]=s[i]+A[i];
  up(i,1,N-1){
    ans+=A[i-1]*(s[N]-s[i]);
  }
  out(ans%mod);
}
int main(void){
  BEGIN;
  solve();
  END;
}
