#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <string>
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
using namespace std;

/*----------macros----------*/

//output================
#define endl '\n'
#define fcout cout << fixed << setprecision(15)

//typedef===============
typedef long long       ll;
typedef long double     ld;
typedef pair<int, int>  Pii;
typedef pair<ll, ll>    Pll;

//const number==========
constexpr ll INF9   = (ll)1e9 + 1;
constexpr ll INF18  = (ll)1e18 + 1;
constexpr ll MOD    = 1000000007;
constexpr ld PI     = 3.141592653589793L;

//member================
#define pb push_back
#define eb emplace_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

//others================
#define all(x)          (x).begin(), (x).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define rep(i, n)       for(int i = 0; (i) < (n); ++(i))
#define rrep(i, n)      for(int i = n - 1; (i) >= 0 ; --(i))
#define For(i, a, b)    for(int i = (a); (i) < (b) ; ++(i))
#define CtoI(c)         int((c)) - int('0')

//functions=============
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

bool isPrime(int n){
    if(n < 2) return false; else if(n == 2) return true; else if(n%2 == 0) return false;
    double sqrtNum = sqrt(n); for(int i = 3;i <= sqrtNum; i += 2) if(n%i == 0) return false;
    return true;
    }

//vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
//vector<int> dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };

/*--------additional--------*/



/*----------main------------*/

int main() {
/*----------fastio----------*/
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
/*----------solve-----------*/

    int n, m; cin >> n >> m;
    cout << (n > m ? "No" : "Yes") << endl;

return 0;
}