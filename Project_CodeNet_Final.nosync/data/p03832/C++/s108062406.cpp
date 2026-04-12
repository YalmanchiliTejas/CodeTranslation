#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <array>
#include <tuple>
#include <utility>
#include <cctype>
#include <typeinfo>
using namespace std;

#define len(x)  (int((x).size()))
#define append push_back
#define pp make_pair
#define ff(a, b)    for (int a = 0; a < int(b); ++a)
#define ii(n)    ff(i, n)
#define kk(n)    ff(k, n)
#define mm(n)    ff(m, n)
#define fff(a, b, c) for (int a = int(b); a < int(c); ++a)
#define iii(a, b) fff(i, a, b)
#define kkk(a, b) fff(k, a, b)
#define mmm(a, b) fff(m, a, b)
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define all(x)  (x).bb, (x).ee
#define ite(v)   decltype((v).bb)
#define fe(i, v) for(ite(v) i = (v).bb; i != (v).ee; ++i)
#define err(...)    { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#define zz(array, byte)   memset(array, byte, sizeof(array));

using LL = long long;
using pii = pair<int, int>;


const LL INF = 9223372036854775807LL;
//const int INF = 2147483647;
   
const LL MOD = LL(1e9) + 7;



LL expmod(LL a, LL b) {
    if (0 == b) return 1LL;
    LL rr = expmod(a, b >> 1);
    rr = (rr * rr) % MOD;
    if (b & 1)
        return (rr * a) % MOD;
    return rr;
}

const int MAXCOMB = 1007;
LL factorial[MAXCOMB];
LL inverse[MAXCOMB];


LL choose(int n, int k) {
    LL rr = (factorial[n] * inverse[n-k]) % MOD;
    return (rr * inverse[k]) % MOD;
}

int N, A, B, C, D;

LL cache[1007][1007];
LL dp(int remaining, int nextsize) {
    if (remaining == 0)
        return 1LL;
    if (nextsize > B)
        return 0;
    if (nextsize > remaining)
        return 0;
    LL &entry = cache[remaining][nextsize];
    if (-1LL != entry)
        return entry;

    LL rr = dp(remaining, nextsize+1);
    fff (gcount, C, D+1) {
        if (gcount*nextsize > remaining)
            break;
        LL further = dp(remaining - gcount*nextsize, nextsize+1);
        if (0 == further)
            continue;
        int rem = remaining;
        ii (gcount) {
            further = (further * choose(rem, nextsize)) % MOD;
            rem -= nextsize;
        }
        further = (further * inverse[gcount]) % MOD;
        rr = (rr + further) % MOD;
    }       
    //printf("Putting %d for %d %d\n", int(rr), remaining, nextsize);

    return entry = rr;
}


int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout << '\n';
    
    zz(cache, -1);
    factorial[0] = 1LL;
    iii (1, MAXCOMB)
        factorial[i] = (factorial[i-1] * LL(i)) % MOD;
    ii (MAXCOMB)
        inverse[i] = expmod(factorial[i], MOD-2);

    cin >> N >> A >> B >> C >> D;

    
    LL rr = dp(N, A);


    cout << rr << '\n';

    return 0;
}

