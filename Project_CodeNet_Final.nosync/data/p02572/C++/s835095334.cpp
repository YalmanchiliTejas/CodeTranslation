#define inf 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define m_p  make_pair
#define ull unsigned long long
#define spd  ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
const ll N = 2e5 + 5;
ll arr[N];
const ll M = 1e9+7;
int main()
{
    spd

    ll n,i,j,k,sum=0,ans=0,var=0;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(i=0;i<n;i++)
    {
        sum+=arr[i];

        sum%=M;
    }

    for(i=0;i<n-1;i++)
    {
        sum-=arr[i];

        if(sum<0)sum+=M;

        ans+=((arr[i]%M)*(sum%M))%M;
        ans%=M;
    }

    cout<<ans<<endl;
}
