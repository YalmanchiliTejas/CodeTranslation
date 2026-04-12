#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007ll
#define mod1 998244353ll
#define inf (ll)1e18+1
#define endl "\n"
using namespace std::chrono;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll ar[n];
    ll sum=0;
    for(ll x=0;x<n;x++){
        cin>>ar[x];
        sum+=ar[x];
    }
    ll dp1[n][n];
    for(ll length=1;length<=n;length++){
        for(ll x=0;x<n;x++){
            ll upto=x+length-1;
            if(upto>=n){
                break;
            }
            // dp1[x][upto]=max(ar[x]+min(dp1[x+2][upto],dp1[x+1][upto-1]),ar[upto]+min(dp1[x][upto-2],dp1[x+1][upto-1]));
            ll sum1=0,sum2=0,sum3=0;
            if(x+2<=upto){
                sum1=dp1[x+2][upto];
            }
            if(x+1<=upto && upto-1>=x){
                sum2=dp1[x+1][upto-1];
            }
            if(upto-2>=x){
                sum3=dp1[x][upto-2];
            }
            dp1[x][upto]=max(ar[x]+min(sum1,sum2),ar[upto]+min(sum2,sum3));
        }
    }
    ll X=dp1[0][n-1];
    ll Y=sum-X;
    cout<<X-Y<<endl;
    return 0;
}