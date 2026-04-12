// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
//#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
typedef long long ll;
#define rep(i, z, n) for(int i = z; i < n; i++)
//const int INF = 1<<29;
const ll MOD = 1000000007;
#define P pair<int, int>
using namespace std;

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};
ll powmod(ll x, ll n, ll mod){
    //pow(x, n) % mod
    int ret = 1;
    while(n > 0){
        if(n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A.at(i);
    ll sum = 0;
    ll sq = 0;
    rep(i, 0, N){
        sum += A.at(i);
        sum %= MOD;
        
        ll sqi = A.at(i);
        sqi *= A.at(i);
        sqi %= MOD;
        sq += sqi;
        sq %= MOD;
    }
    sum *= sum;
    sum %= MOD;
    sum += MOD;
    sum -= sq;
    sum %= MOD;
    ll syo = powmod(2, 1000000005, 1000000007);
    sum *= syo;
    sum %= MOD;
    
    cout << sum << endl;
    //cout << ll(ll(1000000000) * ll(1000000000) % MOD) << endl;
}