/**
     *  “Experience is the name everyone gives to their mistakes.” – Oscar Wilde
     *
     *  author  :   Prodip Datta
     *  handle  :   prodipdatta7
     *  created :   Saturday 19-September, 2020  06:44:03 PM
**/

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <assert.h>
#include <new>
#include <sstream>
#include <time.h>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

using namespace std ;
using namespace __gnu_pbds ;

#define     ll          long long
#define     ld          long double
#define     ull         unsigned long long
#define     pii         pair< int, int >
#define     pll         pair< ll, ll >
#define     vi          vector< int >
#define     vll         vector< ll >
#define     vvi         vector< vector< int > >
#define     vvii         vector< vector< pii > >
#define     debug(x)    cerr << #x << " = " << x << '\n' ;
#define     rep(i,b,e)  for(__typeof(e) i = (b) ; i != (e + 1) - 2 * ((b) > (e))  ; i += 1 - 2 * ((b) > (e)))
#define     all(x)      x.begin() , x.end()
#define     rall(x)     x.rbegin() , x.rend()
#define     sz(x)       (int)x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     eb          emplace_back
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
#define     fread       freopen("input.txt","r",stdin)
#define     fwrite      freopen("output.txt","w",stdout)
#define     TN          typename
#define     FastIO      ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;

typedef tree <pii, null_type, less< pii >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
typedef tree <pii, null_type, less_equal< pii >, rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;

/*
Note :  There is a problem with erase() function in ordered_multiset (for less_equal<int> tag).
        lower_bound() works as upper_bound() and vice-versa.
        Be careful to use.
        i) find_by_order(k) : kth smallest element counting from 0 .
        ii) order_of_key(k) : number of elements strictly smaller than k.
*/

/*###############-> Input Section <-###############*/

template <TN T> inline void Int(T &a) {
    bool minus = false; a = 0; char ch = getchar();
    while (true) { if (ch == '-' or (ch >= '0' && ch <= '9')) break; ch = getchar(); }
    if (ch == '-') minus = true; else a = ch - '0';
    while (true) { ch = getchar(); if (ch < '0' || ch > '9') break; a = a * 10 + (ch - '0'); }
    if (minus)a *= -1 ;
}
template < TN T, TN T1 > inline void Int(T &a, T1 &b) {Int(a), Int(b) ;}
template < TN T, TN T1, TN T2 > inline void Int(T &a, T1 &b, T2 &c) {Int(a, b), Int(c) ;}
template < TN T, TN T1, TN T2, TN T3 > inline void Int(T &a, T1 &b, T2 &c, T3 &d) {Int(a, b), Int(c, d) ;}
template < TN T, TN T1, TN T2, TN T3, TN T4> inline void Int(T &a, T1 &b, T2 &c, T3 &d, T4 &e) {Int(a, b), Int(c, d, e) ;}
template<typename T, typename U> inline void cmin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void cmax(T &x, U y) { if (x < y) x = y; }

/*###############-> Debugger <-###############*/

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<TN T, TN... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}
#else
#define error(args...)
#endif

template<class ValueType>
bool unstable_remove(
    typename std::vector<ValueType>& container,
    typename std::vector<ValueType>::iterator it
) {
    auto lastEl = container.end() - 1;
    if (it != lastEl) {
        *it = std::move(*lastEl);
    }
    container.pop_back();
}

/******************************************
#Rows are numbered from top to bottom.
#Columns are numbered from left to right.
Moves : L, U, R, D, LU, RU, RD, LD.
******************************************/
int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1} ;
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1} ;

/*###############-> Constraints <-###############*/

const int N          = (int)2e5 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;
const int mod        = (int)1e9 + 7 ;
const double EPS     = (double)1e-9 ;
const double PI      = (double)acos(-1.0) ;


inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}

/*...... ! Code starts from here ! ......*/


int main() {
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
#endif

    int test = 1 , tc = 0 ;
    //Int(test) ;
    while (test--) {
        ll n ;
        int x, m ; Int(n, x, m) ;
        if (n == 1) {
            cout << x << '\n' ;
        }
        else {
            if (m == 1) {
                cout << x << '\n' ;
            }
            else {
                if (x == 0)cout << 0 << '\n' ;
                else if (x == 1)cout << n << '\n' ;
                else {
                    ll k = n - 1 ;
                    long long sum = x ;
                    vector < int > used(m, 0) ;
                    vector < ll > dp(maxN, 0);
                    used[x] = 1 ;
                    int itr = 2 ;
                    dp[1] = x ;
                    while (k--) {
                        x = mul(x, x, m) ;
                        sum += x ;
                        if (x == 1) {
                            sum += k ;
                            return cout << sum << '\n', 0 ;
                        }
                        else if (x == 0) {
                            return cout << sum << '\n', 0 ;
                        }
                        else if (used[x] > 0) {
                            --itr ;
                            int st = used[x] - 1 ;
                            ll cur = dp[itr] - dp[st] ;
                            ll lf = n - st ;
                            int len = itr - st ;
                            ll h = lf / len ;
                            sum = cur * h ;
                            int id = lf % len ;
                            sum += dp[st + id] ;
                            error(used[x], itr, x, h, id, lf, len, st)
                            return cout << sum << '\n', 0 ;
                        }
                        used[x] = itr ;
                        dp[itr] = x ;
                        dp[itr] += dp[itr - 1] ;
                        error(x, itr)
                        ++itr ;

                    }
                    cout << sum << '\n' ;
                }
            }

        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0 ;
}