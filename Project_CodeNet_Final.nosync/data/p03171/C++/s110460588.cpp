#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll   long long
#define ld long double
#define endl '\n'
#define INF 10000000000000000
#define pll pair<ll,ll>
#define ff first
#define ss second

using namespace std;
const ll N = 3005;
const ll MOD = 10e8+7;
ll dp[N][N];
ll a[N];
int main()
{
 //freopen("input.txt","r",stdin);
 //  freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n;
    for(ll i =1;i<=n;i++) {
        cin>>a[i];
    }
    for(ll l = n;l>=1;l--) {
        for(ll r = l;r<=n;r++) {
            if(l==r)
                dp[l][r]=a[l];
            else
                dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
        }
    }
    cout<<dp[1][n];
    // ������ ������

}
