#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
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
    boolean isMovable ( int x, int y, int w, int h ) {
        return ( x >= 0 && y >= 0 && x < w && y < h );
    }
}

namespace Rlyeh {

    int n, m;
    Vi vi[8];
    int dp[8][2][2][2][2][2][2][2][2];

    int dfs ( int pos, String bit ) {
        boolean tmp[8];
        boolean flg = true;
        memset(tmp, false, sizeof(tmp));
        for ( int i = 0; i < n; i++ ) {
            if ( bit[i] == 't' ) {
                tmp[i] = true;
            }
            else {
                tmp[i] = false;
                flg = false;
            }
        }
        if ( ~dp[pos][tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]][tmp[5]]
                [tmp[6]][tmp[7]] )
            return dp[pos][tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]]
                    [tmp[5]][tmp[6]][tmp[7]];
        if ( flg ) {
            return 1;
        }
        int rec = 0;
        for ( int i = 0; i < vi[pos].size(); i++ ) {
            unless ( tmp[vi[pos][i]] ) {
                String nw = bit;
                nw[vi[pos][i]] = 't';
                rec += dfs(vi[pos][i], nw);
            }
        }
        return dp[pos][tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]][tmp[5]]
            [tmp[6]][tmp[7]] = rec;
    }

    signed call_of_Cthulhu( signed datum ) {

        read n >> m;
        for ( int i = 0; i < m; i++ ) {
            int a, b;
            read a >> b;
            a--;
            b--;
            vi[a].bash(b);
            vi[b].bash(a);
        }

        String bit = "t";
        for ( int i = 1; i < n; i++ ) {
            bit += "f";
        }

        memset(dp, -1, sizeof(dp));

        echo dfs(0, bit) fin;

        return 0;
    }
}

signed main(){std::cin.tie(0); std::ios::sync_with_stdio(false); int main_result = Rlyeh::call_of_Cthulhu(114514); return 0;}
