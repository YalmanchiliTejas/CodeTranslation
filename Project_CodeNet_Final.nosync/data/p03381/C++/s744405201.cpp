#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#define bogo_sort   std::sort
#define bozo_sort   std::stable_sort
#define alles(obj)  obj.begin(), obj.end()
#define elif        else if
#define unless(flg) if(!(flg))
#define elless(flg) else if(!(flg))
#define echo        std::cout <<
#define read        std::cin >>
#define endl        std::endl
#define fin         << '\n'
#define bash        push_back
#define makePair    std::make_pair
#define _           << ' ' <<
// type-define
#define Stack       std::stack
#define Queue       std::queue
#define Set         std::set
#define PQueue      std::priority_queue
#define Vector      std::vector
#define Pair        std::pair
#define Map         std::map
#define HashMap     std::unordered_map
#define Greater     std::greater
using String  =     std::string;
using llong   =     long long;
using boolean =     bool;
using Pii     =     Pair<int, int>;
using Vi      =     Vector<int>;
using Vii     =     Vector<Pii>;
// utils
constexpr int   dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int   dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
constexpr int   INF  = 0x3f3f3f3f;
constexpr llong LINF = 0x3f3f3f3f3f3f3f3fLL;

namespace {
    template<class A, class B> A power ( llong x, llong n, llong mod ) {
        llong ans = 1;
        while ( n > 0 ) {
            if ( n & 1 ) ans = ( ans * x ) % mod;
            x = ( x * x ) % mod;
            n >>= 1;
        }
        return ans;
    }
    template<class A, class B> A power ( A x, B n ) { return power( x, n, 1000000007 ); }
    template<class A> A gcd ( A x, A y ) { return x % y ? gcd( y, x % y ) : y; }
    template<class A, class B> A lcm   ( A x,  B y ) { return ( x / gcd(x, y) * y ); }
    template<class A> inline A abs ( A n ) { return ( n < 0 ) ? -n : n; }
    template<class A, class B> inline bool chmax ( A &a, const B &b ) { return b > a ? a = b, true : false; }
    template<class A, class B> inline bool chmin ( A &a, const B &b ) { return b < a ? a = b, true : false; }
    boolean isMovable ( int x, int y, int w, int h ) {
        return ( x >= 0 && y >= 0 && x < w && y < h );
    }
}

namespace Rlyeh {

    Vi vi, bi;
    int left, right;

    signed call_of_Cthulhu( signed datum ) {

        int n;
        read n;
        for ( int i = 0; i < n; i++ ) {
            int a;
            read a;
            vi.bash(a);
            bi.bash(a);
        }

        bozo_sort(alles(bi));
        left = bi[n/2-1];
        right = bi[n/2];
        for ( int i = 0; i < n; i++ ) {
            if ( vi[i] < right ) {
                echo right fin;
            }
            else {
                echo left fin;
            }
        }


        return 0;
    }
}

signed main(){std::cin.tie(0); std::ios::sync_with_stdio(false); int main_result = Rlyeh::call_of_Cthulhu(114514); return 0;}
