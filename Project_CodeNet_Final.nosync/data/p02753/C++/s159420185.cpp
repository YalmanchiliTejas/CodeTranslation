// ---------- BEG ../defs.hpp BEG ----------
#ifndef atcoder_defs_hpp
#define atcoder_defs_hpp
#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
using i8t = std::int64_t;
using u8t = std::uint64_t;
using vi8t = std::vector<i8t>;
using vvi8t = std::vector<std::vector<i8t>>;
using vu8t = std::vector<u8t>;
#include <limits>
static const i8t i8t_max=numeric_limits<i8t>::max();
static const i8t i8t_min=numeric_limits<i8t>::min();
#include <unordered_map>
#include <unordered_set>
template<typename Key,typename Value> using map_t=std::unordered_map<Key, Value>;
template<typename Key> using set_t=std::unordered_set<Key>;
#define F3(i,i0,iN,step) for(i8t i=i0,i##_N=iN;i<i##_N;i+=step)
#define F2(i,i0,iN) F3(i,i0,iN,1)
#define F(i,N) F3(i,0,N,1)
#define FR(i,N) for(i8t i=N;i--;)
#define R(V) i8t V;std::cin>>V;
#define RV(V,N) std::vector<i8t> V;F(_i,N){R(_x)V.push_back(_x);}
#define RL1(line) std::getline(std::cin,line);
#define RL(line) std::string line;RL1(line)
#define RM(V,L,C) std::vector<char> V;F(_i,L){RL(_l)F(_j,C)V.push_back(_l[_j]);}
#define P(X) std::cout<<(X)<<std::endl;
template<typename T> T umax(T& ans,T const& value) {if(value>ans)ans=value;return ans;}
template<typename T> T umin(T& ans,T const& value) {if(value<ans)ans=value;return ans;}
template<typename T> struct identity { using type = T; };
#endif
// ---------- END ../defs.hpp END ----------

int main() {
  RL(line)
  P(!(line=="AAA"||line=="BBB")?"Yes":"No");
  return 0;
}
