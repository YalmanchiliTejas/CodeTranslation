#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <random>
#include <complex>
#include <utility>
#include <tuple>
#include <memory>

#include <array>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <csignal>
#include <cstdint>
#include <cstddef>

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif
#include <cassert>
#include <stdexcept>
#include <exception>

// << pair
template <typename T1, typename T2>
std::ostream&operator<<(std::ostream&os,const std::pair<T1,T2>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
// << container
template <typename C>
std::ostream&_debug_go(std::ostream&os,const C&v) {bool first=true;os<<"[";for(auto i:v){if(!first)os<<", ";os<<i;first=false;}return os<<"]";}
// << {vector, set, map} delegating to _debug_go
template<typename T> std::ostream&operator<<(std::ostream&os,const std::vector<T>&v){return _debug_go(os, v);}
template<typename T> std::ostream&operator<<(std::ostream&os,const std::set<T>&v){return _debug_go(os, v);}
template<typename T1, typename T2> std::ostream&operator<<(std::ostream&os,const std::map<T1,T2>&v){return _debug_go(os, v);}
struct Debugger{template<typename T>Debugger&operator,(const T&v){std::cerr<<v<<" "; return *this;}} dbg;
#ifndef NDEBUG
#define debug(args...) do {dbg,args; cerr << "\n";} while(0)
#else
#define debug(args...)
#endif

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ITER(i, s, e) for (auto i((s)); i != (e); ++i)
#define IT(i, c) ITER(i, (c).begin(), (c).end())

using namespace std;

using ui = uint32_t;
using ll = int64_t;
using ull = uint64_t;
template <typename T = int> using Pt = complex<T>;

template <typename T>
T cross(const Pt<T>& a, const Pt<T>& b) { return a.real() * b.imag() - a.imag() * b.real(); }

template <typename T>
bool cmpPt(const Pt<T>& a, const Pt<T>& b) {
    return a.real() < b.real() || (a.real() == b.real() && a.imag() < b.imag());
}
// END TEMPLATE

int solve(int N, const vector<int>& A) {
    set<pair<int, int>> ends;
    REP(i, N) {
        auto it = ends.lower_bound({A[i], -1});
        if (it != ends.begin()) {
            --it;
            ends.erase(it);
        }
        ends.emplace(A[i], i);
    }
    return ends.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    for (int& a : A) cin >> a;
    cout << solve(N, A) << '\n';

    return 0;
}
