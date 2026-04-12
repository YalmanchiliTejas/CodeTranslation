#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;
 
int main() {
    int n;
    cin >> n;
    vi a(n+10);
    rep(i,n) cin >> a[i];
    a[n] = 1;
    ll sum[200010] = {};
    for(int i = n-1; i >= 0; i--) (sum[i] += a[i]+sum[i+1]) %= MOD;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        (ans += a[i]*sum[i+1]) %= MOD;
    }
    cout << ans << endl;
	return 0;
}