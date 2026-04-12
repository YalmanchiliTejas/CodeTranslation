#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    ll n;   cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n+2, vector<ll>(n+2, 0));
    rep(i, n){
        cin >> a[i];
        // dp[i][i] = a[i];
    }
    FOR(len, 1, n+1){
        for(int i=0; i<=n; i++){
            int j = i+len;
            if(n<j) continue;
            if((n-len)%2==0){
                dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1]);
            }else{
                dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1]);
            }
        }
    }
    cout << dp[0][n] << endl;
    
}
