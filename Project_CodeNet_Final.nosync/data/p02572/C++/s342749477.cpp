//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define endl            "\n"
#define pb              push_back
#define ppb              pop_back
#define mp              make_pair
#define pii             pair<int, int>
#define vi              vector<int>
#define all(x)          (x).begin(), (x).end()
#define mii             map<int, int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int, vi, greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e18
#define sp(x,y)         fixed << setprecision(y) << x
#define w(x)            int x; cin >> x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int M = 1e9 + 7;
inline int ceili(int x, int y) { return (x + y - 1) / y; }
inline int mod(int x) { return ((x % M + M) % M); }
inline int add_mod(int a, int b) { return mod(mod(a) + mod(b)); }
inline int mul_mod(int a, int b){ return mod(mod(a) * mod(b)); }
 
void solve()
{
    int n; cin >> n;
    vector<int> a(n);

    for(auto &it : a) cin >> it;

    vector<int> suf(n + 1);
    for(int i = n - 1; i >= 1; --i) {
        suf[i] = suf[i + 1] + a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans = add_mod(ans, mul_mod(a[i], suf[i + 1]));
    }

    cout << ans << endl;
}
 
int32_t main()
{
    FIO;

    solve();

    return 0;
}