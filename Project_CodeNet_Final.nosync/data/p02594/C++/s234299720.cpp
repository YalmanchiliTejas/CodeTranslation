//#pragma gcc optimize("Ofast,no-stack-protector,tune=native")
//#pragma gcc optimize("sse,sse2,sse3,sse4,ssse3")
//#pragma gcc optimize("O3")
//#pragma gcc optimize("abm,mmx,avx,avx2,fast-math,section-anchors")
//#pragma GCC optimize("Ofast,no-stack-protector,delete-null-pointer-check")
//#pragma GCC target("tune=native")
//#pragma GCC diagnostic error "-std=c++11"
//#pragma GCC target("avx")
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline")
//#pragma GCC optimize("-fgcse")
//#pragma GCC optimize("-fgcse-lm")
//#pragma GCC optimize("-fipa-sra")
//#pragma GCC optimize("-ftree-pre")
//#pragma GCC optimize("-ftree-vrp")
//#pragma GCC optimize("-fpeephole2")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("-fsched-spec")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-falign-jumps")
//#pragma GCC optimize("-falign-loops")
//#pragma GCC optimize("-falign-labels")
//#pragma GCC optimize("-fdevirtualize")
//#pragma GCC optimize("-fcaller-saves")
//#pragma GCC optimize("-fcrossjumping")
//#pragma GCC optimize("-fthread-jumps")
//#pragma GCC optimize("-funroll-loops")
//#pragma GCC optimize("-fwhole-program")
//#pragma GCC optimize("-freorder-blocks")
//#pragma GCC optimize("-fschedule-insns")
//#pragma GCC optimize("inline-functions")
//#pragma GCC optimize("-ftree-tail-merge")
//#pragma GCC optimize("-fschedule-insns2")
//#pragma GCC optimize("-fstrict-aliasing")
//#pragma GCC optimize("-fstrict-overflow")
//#pragma GCC optimize("-falign-functions")
//#pragma GCC optimize("-fcse-skip-blocks")
//#pragma GCC optimize("-fcse-follow-jumps")
//#pragma GCC optimize("-fsched-interblock")
//#pragma GCC optimize("-fpartial-inlining")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("-freorder-functions")
//#pragma GCC optimize("-findirect-inlining")
//#pragma GCC optimize("-fhoist-adjacent-loads")
//#pragma GCC optimize("-frerun-cse-after-loop")
//#pragma GCC optimize("inline-small-functions")
//#pragma GCC optimize("-finline-small-functions")
//#pragma GCC optimize("-ftree-switch-conversion")
//#pragma GCC optimize("-foptimize-sibling-calls")
//#pragma GCC optimize("-fexpensive-optimizations")
//#pragma GCC optimize("-funsafe-loop-optimizations")
//#pragma GCC optimize("inline-functions-called-once")
//#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("avx2, O3")

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <deque>
#include <map>
#include <fstream>
#include <utility>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <random>
#include <math.h>
#include <cassert>
#include <bitset>
#include <chrono>
#include <sstream>
#include <array>

using namespace std;

#define DEBUG_VIVOD " SHTO-TO POSHLO NE TAK\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define pf push_front
#define _USE_MATH_DEFINES
#define filin(x) freopen(x, "r", stdin)
#define filout(x) freopen(x, "w", stdout)
#define deq deque
#define vec vector
#define umap unordered_map
#define uset unordered_set
#define nan nullptr
#define rtn(x) {return x;}

//typedef long long ll;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned long long ui;

#define INF 1e9
mt19937 prof_rand(time(0));
#define rand() prof_rand()

signed main() {
    ll x; cin >> x;
    cout << (x >= 30 ? "Yes" : "No");
    return 0;
}

