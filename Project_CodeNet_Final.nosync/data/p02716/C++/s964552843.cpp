#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <stack>
#include <deque>
#include <ctime>
#include <random>
#include <cassert>
#include <cmath>
#include <climits>
#include <queue>
#include <cstring>
#include <bitset>
#include <iomanip>
#include <chrono>

/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("popcnt")
#pragma GCC target("avx2")
*/


#ifdef LOCAL
    #define dbg(x) cout << #x << " : " << x << endl;
#else 
    #define dbg(x)
#endif

#define int long long
#define fi(a,b) for (int i=a;i<b;i++)
#define fj(a,b) for (int j=a;j<b;j++)
#define fk(a,b) for (int k=a;k<b;k++)
#define fi1(a,b) for (int i=a-1;i>=b;i--)
#define fj1(a,b) for (int j=a-1;j>=b;j--)
#define fk1(a,b) for (int k=a-1;k>=b;k--)
#define fx(x,a) for (auto& x : a)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rep1(i, a, b) for (int i = a - 1; i >= b; --i)
#define siz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

template<typename T1, typename T2>inline void mine(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void maxe(T1 &x, T2 y) { if (x < y) x = y; }

ostream& operator << (ostream &a, const vector<int> &b) {
    for (auto k : b) cout << k << ' ';
    return a;
}


typedef long long ll;
typedef unsigned long long ull;
typedef char ch;
typedef string str;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<ch> vch;
typedef vector<vch> vvch;
typedef vector<str> vs;



const int MOD = 1000000007;
const int INF = 1000000050;
const long long BIG = (long long)2e18 + 50;
const int MX = 200010;
const double EPS = 1e-9;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[MX][2][2]; // done, delta + 1, last
int a[MX];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    fi(0, n) 
        cin >> a[i];
    dp[0][1][1] = a[0];
    dp[0][1][0] = dp[0][0][1] = -BIG;
    fi(1, n) {
        dbg(i);
        dp[i][1][1] = a[i] + ((i + 1) % 2 ? dp[i - 1][1][0] : dp[i - 1][0][0]);
        dp[i][0][1] = a[i] + ((i + 1) % 2 ? dp[i - 1][0][0] : -BIG - a[i]);
        dp[i][1][0] = ((i + 1) % 2 ? -BIG : dp[i - 1][1][1]);
        dp[i][0][0] = ((i + 1) % 2 ? max(dp[i - 1][1][1], dp[i - 1][1][0]) : max(dp[i - 1][0][1], dp[i - 1][0][0]));
        dbg(dp[i][0][0]);
        dbg(dp[i][0][1]);
        dbg(dp[i][1][0]);
        dbg(dp[i][1][1]);
    }
    if (n % 2)
        cout << max(dp[n - 1][0][0], dp[n - 1][0][1]);
    else
        cout << max(dp[n - 1][1][0], dp[n - 1][1][1]);
    cout << '\n';
}