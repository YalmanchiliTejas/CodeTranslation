#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<pair<int, int>, int> ppi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vll;
typedef bitset<60> Bitset;
const ll INFL = 1LL << 60;
const int INF = 1000000005;
const int MAX = 300000;
const int MOD = 1000000007;
struct Graph{int to,coin; ll cost;};
struct Edge{int from,to,coin; ll cost;};
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll LCM(ll a, ll b) { return (a * b) / GCD(a, b); }
//------------------------------------------------------------------------------------------------------------------------------

int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;
    vl a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    vl sum(n+1,0);
    for(int i = n-1; i >= 0; i--) {
        sum[i] = (sum[i+1] + a[i]) % MOD;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (a[i] * sum[i+1]) % MOD;
        ans %= MOD;
    }
    cout<<ans<<endl;
    
}
