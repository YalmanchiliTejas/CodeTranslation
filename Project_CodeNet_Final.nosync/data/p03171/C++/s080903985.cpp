#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed;cout<<setprecision(10);
#define randomINIT mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define gcj cout<<"Case #"<<tc<<": "
#define ld long double
#define pll pair<ll,ll>
#define vll vector<pll>
#define vl vector<ll>
#define f first
#define s second
#define pb push_back
#define MAP map<ll,ll>
#define MAPs map<ll,sl>
#define MAPv map<ll,vl>
#define mset1(x,val,n) foo(i,0,n+5) x[i]=val;
#define mset2(x,val,n,m) foo(i,0,n+5) foo(j,0,n+5) x[i][j]=val;
#define mod 1000000007
#define foo(i,a,b) for(ll i=(a);i<=(b);i++)
#define rep(i,a,b) for(ll i=(a);i>=(b);i--)
#define FOR(i,v) for(auto &(i):(v))
#define OUTv(v) for(auto &i:(v)) cout<<i<<" ";
#define deb1(a) cout<<a<<"\n";
#define deb2(a,b) cout<<a<<" "<<b<<"\n";
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define deb4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define sl set<ll>
#define sll set<pll>
#define ub upper_bound
#define lb lower_bound
using namespace std;

const ll   INF = 0x7f7f7f7f7f7f7f7f;
const ll NINF = -INF;
const ll MAXN  = 1e+6 + 8;

int dx8[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};

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

#define UMAP unordered_map<ll,ll,custom_hash>

ll t = 1; randomINIT;
//<<-----Declare Variable Here------->>//
ll n, a[6000], dp[6000][6000], m = 0, ans = 0;

//<<-----Implement Functions Here---->>//
ll solve(ll l, ll r) {
    if (l == r) { return a[l];}
    if (dp[l][r] != INF) { return dp[l][r];}
    dp[l][r] = max(a[l] - solve(l + 1, r), a[r] - solve(l, r - 1));
    return dp[l][r];
}

//<<-----Start of Main--------------->>//
void MAIN(ll tc) {
    cin >> n;
    ll sum = 0;
    mset2(dp, INF, n, n);
    foo(i, 1, n) cin >> a[i], sum += a[i];
    ll x = solve(1, n);
    // cout << sum << " " << x << "\n";
    // cout << (sum + x) / 2 << "\n";
    cout << x << "\n";


}

int main() {
    fastio;
    // cin >> t;
    foo(i, 1, t) {
        MAIN(i);
    }

// #ifndef ONLINE_JUDGE
//  cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
// #endif
}