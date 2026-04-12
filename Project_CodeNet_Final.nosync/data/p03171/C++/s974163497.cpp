#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
#define pii pair<ll int, ll int>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define repi(i, n) for(ll i=0; i<n; i++)
#define rep(i, a, b) for(ll i=a; i<=b; i++)
#define M 1000000007
#define INF 1e10

using namespace std;

int main() {
    ios
    ll n;
    cin>>n;
    vector <ll> a(n);
    repi(i, n) cin>>a[i];
    ll dp[n][n][2];
    repi(i, n) {
        dp[i][i][0] = a[i];
        dp[i][i][1] = -a[i];
    }
    for(ll j=1; j<n; j++){
        for(ll i=0; i+j<n; i++){
            dp[i][i+j][0] = max(a[i] + dp[i+1][i+j][1], a[i+j] + dp[i][i+j-1][1]);
            dp[i][i+j][1] = min(dp[i+1][i+j][0] - a[i], dp[i][i+j-1][0] - a[i+j]);
        }
    }
    cout<<dp[0][n-1][0]<<endl;
    return 0;
}
