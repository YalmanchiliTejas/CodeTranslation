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
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <climits>
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
#define UMap        std::unordered_map
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
    llong power ( llong x, llong n, llong mod ) {
        llong ans = 1;
        while ( n > 0 ) {
            if ( n & 1 ) ans = ( ans * x ) % mod;
            x = ( x * x ) % mod;
            n >>= 1;
        }
        return ans;
    }
    llong power ( llong x, llong n ) { return power( x, n, 1000000007 ); }
    llong gcd   ( llong x, llong y ) { return x % y ? gcd( y, x % y ) : y; }
    llong lcm   ( llong x, llong y ) { return ( x / gcd(x, y) * y ); }
    llong abs   ( llong n )          { return ( n < 0 ) ? -n : n; }
    template<class A, class B>inline bool chmax ( A &a, const B &b ) { return b > a ? a = b, true : false; }
    template<class A, class B>inline bool chmin ( A &a, const B &b ) { return b < a ? a = b, true : false; }
    boolean isMovable ( int x, int y, int w, int h ) {
        return ( x >= 0 && y >= 0 && x < w && y < h );
    }
}

namespace Rlyeh {

    signed call_of_Cthulhu( signed datum ) {

        int n;
        read n;
        if ( n == 3 || n == 5 || n == 7 ) echo "YES";
        else echo "NO";
        echo endl;

        return 0;
    }
}

signed main(){std::cin.tie(0); std::ios::sync_with_stdio(false); echo std::fixed << std::setprecision(8); int main_result = Rlyeh::call_of_Cthulhu(114514); return main_result;}
