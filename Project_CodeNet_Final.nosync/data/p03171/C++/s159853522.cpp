#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
 
const int N = 1e5 + 5;
const int mod = 1e9+7;
const ll INF = (ll)1e18;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<ll> v(n+1), pre(n+1, 0);
    for(int j = 1; j <= n; j++) cin >> v[j], pre[j] = pre[j-1]+v[j];

    vector< vector<ll> > dp(n+2, vector<ll>(n+2, 0));
    for(int j = 1; j <= n; j++){
        for(int k = j; k > 0; k --)
            dp[k][j] = max(v[k] + (pre[j] - pre[k-1] - v[k] - dp[k+1][j]), v[j] + (pre[j] - pre[k-1] - v[j] - dp[k][j-1]));
    }
    cout << (dp[1][n] - (pre[n] - dp[1][n]));
    return 0;
}