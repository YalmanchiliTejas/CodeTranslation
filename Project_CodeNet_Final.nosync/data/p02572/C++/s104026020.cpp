#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,i,j,k;
    cin>>n;
    ll ar[n],br[n];
    for(i=0;i<n;i++)
        cin>>ar[i];
    br[n-1]=ar[n-1];
    for(i=n-2;i>=0;i--){
        br[i]=ar[i]+br[i+1];
    }
    ll ans=0;
    ll m=1000000007;
    for(i=n-2;i>=0;i--){
        ans=((ans%m)+((ar[i]%m)*(br[i+1]%m))%m)%m;
    }
    cout<<ans<<endl;
}
