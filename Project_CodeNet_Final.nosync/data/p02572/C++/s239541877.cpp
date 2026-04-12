#ifdef __APPLE__
#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <iomanip>
#include <cmath>
#include <ctgmath>
#include <math.h>
#include <cassert>
#include <chrono>
#else
#include <bits/stdc++.h>
#endif

using namespace std;
#define io ios_base::sync_with_stdio(false), cin.tie(NULL)
#define GFOR(i,a,n) for (i=a;i<n;i++)
#define FOR(i,a,n) for (int i=a;i<n;i++)
#define RFOR(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define tc(t) for (int tc=1; tc<=t; tc++)
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long int> vll;
typedef vector<pair<int, int> > vpi;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll modInverse (ll a) {ll p = mod - 2; return powmod(a, p);}
// head

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    vll prefix(n+1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + a[i-1];
        prefix[i] %= mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += prefix[i-1]*a[i-1];
        ans %= mod;
    }
    cout << ans << "\n";
}

int main() {
    #ifdef LOCAL
    auto t1 = std::chrono::high_resolution_clock::now();
    #endif

    io;
    solve();

    #ifdef LOCAL
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();

    std::cout << "Time Taken: " << duration << "\n";
    #endif

}
// check for edge cases in limits
// printing double may print 1.223232e9 like values, beware of that
// carefully observe simulation of test cases
// multiset erase is does not do what it is supposed to
