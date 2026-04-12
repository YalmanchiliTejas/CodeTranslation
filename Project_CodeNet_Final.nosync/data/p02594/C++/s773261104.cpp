/***
 ** " Any fool can write code that a computer can understand. Good programmers write code that humans can understand "
 **     -- Martin Fowler
***/

/**
  *  Author: dhruv_gheewala
  *  Problem: ac@abc174@a
  *  Date:   02.08.2020
  *  Time:   17:31:04
**/

#if __has_include("debug.h")
    #include "debug.h"
#else
    #include<bits/stdc++.h>
    using namespace std;
    
    #define fundri 108
    #define debug(...) 1729
#endif

#define int int64_t
typedef pair<int, int> pii;
typedef vector<int> vi;

const bool testcases = false;
#define ff first
#define ss second
#define endl '\n'
#define all(s) s.begin(), s.end()

// if vector isn't soted then it will remove consecutive same elements
#define make_unique(vec) vec.erase(unique(all(vec)), vec.end())
#define test int TC = 1;if(testcases)cin >> TC;for(int tc = 1 ; tc <= TC ; tc++)solve(), fundri
#define sort_by(cont,expr) sort(all(cont),[&](const auto &lhs,const auto &rhs){return expr;})

int seed; mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l = 0, int r = INT_MAX) {return uniform_int_distribution<int>(l, r)(rng);}

inline bool in_range(int a, int l, int r) {return (a >= l && a <= r);}
template<typename H, typename ...T>void inp(H &head) {cin >> head;}
template<typename H, typename ...T>void inp(H &head, T &...tail) {cin >> head;inp(tail...);}
template<typename T>bool isPrime(T n) {for(T i = 2; i * i <= n; i++)if(n % i == 0)return false; return n >= 2;}
template<typename T>inline istream &operator >>(istream &in, vector<T> &a) {for(T &x : a)in >> x; return in;}
template<typename T, typename U>inline istream &operator >>(istream &in, pair<T, U> &a) {in >> a.ff >> a.ss; return in;}

void solve();
void fast_io();

int32_t main(int32_t argc, char **argv)
{
    fast_io();
    test;
    return 0;
}

void solve()
{
    int x;
    cin >> x;
    cout << (x >= 30 ? "Yes" : "No") << endl;
}

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef DHRUV_GHEEWALA
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
}