#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
void Google(ll tt){
    cout<<"Case #"<<tt<<": ";
}
 
int main()
{
    IO
    clock_t begin = clock();
    ll n;
    cin>>n;
    ll a[n+1];
    ll sum = 0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    vector <vector<ll>> dp(n+5,vector<ll> (n+5,0));
    for(ll _s=1;_s<=n;_s++)
    {
        for(ll i=1;i<=n;i++)
        {
            if((i+_s-1)>n)
                break;
            ll j=i+_s-1;
            if(_s==1)
                dp[i][j]=a[i];
            else if(_s==2)
                dp[i][j]=max(a[i],a[j]);
            else
                dp[i][j]=max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i][j-2],dp[i+1][j-1]));
        }
    }
    cout<<(dp[1][n] - (sum - dp[1][n]))<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}