#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;
ll pm(int n,int p){
    ll ret = 1;
    ll now = n;
    while(p){
        if(p & 1){
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        p >>= 1;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll>v(n + 5,0);
    fr(i,1,n+1) {
        cin >> v[i];
    }
    ll dp[n+ 5][3] = {};
    for (int i = 1 ; i < n+5 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            dp[i][j] = -1e18;
        }
    }
    dp[1][0] = v[1];
    dp[2][0] = v[2];
    dp[0][0] = 0;
    for(int i = 3 ; i <= n ; i++) {
        for (int j = 0 ; j <= 2 ; j++) {
            for (int k = 0 ; k <= j ; k++) {
                if (i >= k+2) {
                    //cout << i <<
                    //cout << v[i] << endl;
                    dp[i][j] = max(dp[i][j],dp[i-k-2][j-k]+v[i]);
                }
            }
            //cout << i <<' '<<j<<' '<<dp[i][j]<<endl;
        }

    }
    if (n & 1) {
        ll ans = max({dp[n-1][0],dp[n-2][0],dp[n][2]});
        cout << ans << '\n';
    }
    else {
        ll ans = max({dp[n-1][0],dp[n][0],dp[n][1]});
        cout << ans << '\n';
    }
}