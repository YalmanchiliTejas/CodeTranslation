#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:268435456")
#pragma warning( disable : 6031)
#pragma warning( disable : 4244)
#pragma warning( disable : 26451)
#endif
#ifndef _MSC_VER
#pragma GCC target ("sse4.2")
#endif
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#  define __builtin_popcountll __popcnt64
#include <intrin.h>

static inline int __builtin_ctz(unsigned x) {
    unsigned long ret;
    _BitScanForward(&ret, x);
    return (int)ret;
}
static inline int __builtin_ctzll(unsigned long long x) {
    unsigned long ret;
    _BitScanForward64(&ret, x);
    return (int)ret;
}
static inline int __builtin_clz(unsigned x) {
    return (int)__lzcnt(x);
}

static inline int __builtin_clzll(unsigned long long x) {
    return (int)__lzcnt64(x);
}
#endif
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <numeric>
#include <algorithm>
#include <random>
#include <utility>
#include <bitset>
#include <cmath>
#include <sstream>
#include <functional>
#include <iomanip>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <array>

#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define eps (1e-15)
#define ar array

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<double> vd;
typedef vector< vd > vvd;
typedef vector< string > vs;
typedef pair< int, int > pii;
typedef pair<ll, ll> pll;
typedef vector< pii > vpii;
typedef vector< pll > vpll;
typedef vector<ll> vl;
typedef vector<vector<long long>> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tuple<int, int, int> tiii;
const long long mod = int(1e9) + 7;
const int INF = 1e9;
const ll LINF = 1e18;



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout << setprecision(18) << fixed;
#ifdef LOCAL_MACHINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int x;
    cin >> x;
    cout << (x >= 30 ? "Yes" : "No");
    return 0;    
}