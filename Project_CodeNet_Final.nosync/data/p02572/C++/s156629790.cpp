#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////

const ll mod = 1e9+7;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<ll> sum(n+1);
    sum[0] = 0;
    rep(i,n) sum[i+1] = (sum[i]+a[i]);

    ll ans = 0;
    rep(i,n) {
        ans += (a[i]%mod)*((sum[n]-sum[i+1])%mod);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}