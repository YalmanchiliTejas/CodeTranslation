#define ALGORITHM   0
#define CLIMITS     0
#define CMATH       0
#define DEQUE       0
#define LIST        0
#define MAP         0
#define QUEUE       0
#define SET         0

#define DP          0
#define DIRECTIONS  0

#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#if ALGORITHM
#include <algorithm>
#endif
#if CLIMITS
#include <climits>
#endif
#if CMATH
#include <cmath>
#endif
#if DEQUE
#include <deque>
#endif
#if LIST
#include <list>
#endif
#if MAP
#include <map>
#endif
#if QUEUE
#include <queue>
#endif
#if SET
#include <set>
#endif

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

#define endl '\n'
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

using ll = long long;
using P = pair<ll, ll>;

constexpr long double PI = 3.1415926535897932384626433832795028841971L;
constexpr ll INF9 = (1 << 30);
constexpr ll INF18 = (long long)1e18 + 1;
constexpr ll MOD = (int)1e9 + 7;

#if DP
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#endif

#if DIRECTIONS
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vector<int> dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#endif
//
//
//
//
//
/*追加部分*/



/*main関数*/

int main() {
FASTIO;
    int n;
    ll a[200000];
    ll b[200001];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i + 1] = b[i] + a[i];
        b[i + 1] %= MOD;
    }
    ll ans = 0;
    for (int i = n - 1; i >= 1; --i) {
        ans += (a[i] * b[i]) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

return 0;
}