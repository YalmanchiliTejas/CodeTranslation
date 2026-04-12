#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3005;
ll a[maxn], dp[maxn][maxn];
int main()
{
    ll n;
    cin >> n;
    for(ll i=0;i<n;i++)cin >> a[i];
    for(ll l=n-1;l>=0;l--){
        for(ll r=l;r<n;r++){
            if(r == l)dp[l][r]=a[l];
            else dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
