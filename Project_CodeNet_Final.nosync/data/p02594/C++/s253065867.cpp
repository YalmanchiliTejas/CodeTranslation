#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MOD (int)(1e9+7)
#define ceil(x, y) (x%y==0? (x/y) : (x/y+1))
#define FOR(i, N) for(int i = 0; i < N; ++i)
#define FOR1(i, N) for(int i = 1; i <= N; ++i)
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mset(a, v) memset(a, v, sizeof(a))
#define all(v) (v).begin(), (v).end()
#define INF 2e9
#define EPS 1e-9
#define PI 3.141592653589793238
#define int long long
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<int, int, hash<int>> ht; // while using, comment #define int long long  */

void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in3.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int T=1;
    // cin >> T;
    FOR1(tt, T)
    {
        //cout << "Case #" << tt << ": ";
        int x; cin >> x;
        if(x >= 30) cout << "Yes";
        else cout << "No";
        cout << '\n';
    }
    return 0;
}