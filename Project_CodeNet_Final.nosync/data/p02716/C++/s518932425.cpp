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
#else
#include <bits/stdc++.h>
#endif

using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define tc(t) for (int tc=1; tc<=t; tc++)
typedef vector<int> VI;
typedef vector<long long int> VLLI;
typedef vector<pair<int, int> > VPI;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll, ll> PLL;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll modInverse (ll a) {ll p = mod - 2; return powmod(a, p);}
// head

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    if (n == 2) {
        cout << max(a[0], a[1]) << "\n";
        return 0;
    }

    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[n-1][0] = a[n-1];
    dp[n-1][1] = a[n-1];
    dp[n-2][0] = a[n-2];
    dp[n-2][1] = a[n-2];
    dp[n-3][0] = a[n-3];
    dp[n-3][1] = a[n-3] + a[n-1];

    for (ll i = n-4; i >= 0; i--) {
        if ((n-i)%2 == 0) {
            dp[i][0] = max(dp[i+2][0], dp[i+3][1]);
            dp[i][0] += a[i];
            dp[i][1] = dp[i][0];
        } else {
            dp[i][0] = max(dp[i+2][0], max(dp[i+3][0], dp[i+4][1]));
            dp[i][0] += a[i];
            dp[i][1] = a[i] + dp[i+2][1];
        }
    }

    if (n%2 == 0) {
        cout << max(dp[0][0], dp[1][1]) << "\n";
    } else {
        cout << max(dp[0][0], max(dp[1][0], dp[2][1])) << "\n";
    }
}

