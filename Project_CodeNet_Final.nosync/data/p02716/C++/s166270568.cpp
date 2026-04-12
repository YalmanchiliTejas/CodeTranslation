/*
Author- Aasav Badera
Time- Sun Apr 12 17:57:45 2020
*/
#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
// -------------------Standard Traversal Moves---------------------
// vi fx = {1 ,-1 ,0, 0}, fy = {0, 0, -1, 1};
// vi fx = {2, -2, 2, -2,  1, -1, 1, -1}, fy = {1, 1, -1, -1, 2, 2, -2, -2};
// vi fx = {1, 1, 1, -1, -1 , -1, 0, 0}, fy = {1, -1, 0, 1, -1, 0, 1, -1};
// ----------------------------------------------------------------

#define ll                 long long    
#define int                long long                        
#define pb                 push_back                                                     
#define mii                map<ll ,ll >
#define rep(i, a, b)       for(ll  i=a;i<b;i++)
#define dbg(args...)       { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define pii                pair<ll ,ll >
#define ppb                pop_back
#define vi                 vector<ll >
#define vii                vector<pair<ll , ll >>
#define si                 set <ll>
#define hell               1000000007
// #define hell               (ll)998244353
#define all(a)             (a).begin(),(a).end()
#define sz(x)              (ll )x.size()
#define mp                 make_pair
#define yes                cout << "YES" << endl
#define no                 cout << "NO" << endl
#define inf                1e18L+1
#define endl               '\n' 
#define N                  200005
ll n, a[N];
ll dp[N][4][2];
bool vis[N][4][2];
ll go(ll pos, ll cur, ll last)
{
    if(cur < -1)return -inf;
    if(pos == n)return 0;
    if(vis[pos][cur+2][last])return dp[pos][cur+2][last];
    vis[pos][cur + 2][last] = 1;
    ll &ans = dp[pos][cur + 2][last];
    ans = go(pos+1, cur-1, 0);
    if(last == 0)
    {
        ans = max(ans, go(pos+1, cur+1, 1) + a[pos]);
    }
    return ans;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif
    ll tests = 1;
    // cin >> tests;
    while(tests--)
    {
        cin >> n;
        rep( i,0, n)cin >> a[i];
        cout << go(0, n%2, 0) << endl;
    }
    return 0;
}

