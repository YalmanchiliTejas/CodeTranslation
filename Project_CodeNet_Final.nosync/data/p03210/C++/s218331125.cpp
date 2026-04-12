#pragma GCC optimize("O3")

#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
using namespace std;

/*----------macros----------*/

//input, output================
#define fastio                          \
std::ios::sync_with_stdio(false);       \
std::cin.tie(nullptr);                  \
std::cout.tie(nullptr)

#define endl '\n'
#define fcout(a)                        \
cout << fixed << setprecision((int)(a))

//typedef===============
typedef long long       ll;
typedef long double     ld;
typedef vector<int>     Vi;
typedef vector<ll>      Vl;
typedef pair<int, int>  Pii;
typedef pair<ll, ll>    Pll;

//const number==========
constexpr ll INF    = (ll)1e9 + 1;
constexpr ll INFll  = (ll)1e18 + 1;
constexpr ll MOD1   = 1000000007;
constexpr ll MOD2   = 998244353;
constexpr ld PI     = 3.141592653589793L;

//member================
#define psb push_back
#define epb emplace_back
#define psf push_front
#define mkp make_pair
#define fst first
#define snd second

//others================
#define sz(x)                           \
(int) x.size()

#define all(x)                          \
(x).begin(), (x).end()

#define rall(x)                         \
(x).rbegin(), (x).rend()

#define rep(i, n)                       \
for(int i = 0; (i) < (n); ++(i))

#define reps(i, n)                      \
for(int i = 1; (i) <= (n); ++(i))

#define rrep(i, n)                      \
for(int i = n - 1; (i) >= 0 ; --(i))

#define repbit(bit, n)                  \
for(int bit = 0; (bit) < (1 << (n)); ++(bit))

#define ifbit(bit, i)                   \
if((bit) & (1 << (i)))

#define CtoI(c)                         \
int((c)) - int('0')

#define ItoC(c)                         \
char((c) + '0')

//functions=============
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b)
{ return a < b && (a = b, true); }

template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b)
{ return a > b && (a = b, true); }

// Vi  dx = {1, 0, -1, 0},
//     dy = {0, 1, 0, -1};

// Vi  dx2 = { 1,1,0,-1,-1,-1,0,1 },
//     dy2 = { 0,1,1,1,0,-1,-1,-1 };

/*--------additional--------*/



/*----------main------------*/

int main() {
fastio;

    int x; cin >> x;
    if(x == 7 || x == 5 || x == 3){
        cout << "YES" << endl;
        return 0;
    }
    else cout << "NO" << endl;

return 0;
}