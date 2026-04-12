#include<bits/stdc++.h>
#define ll long long int
#define p pair<ll,ll>
#define pp pair<pair<ll,ll>,ll>
#define fi first
#define se second
#define opti ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const ll N = 1e6+6;
ll t,i,j,k,n,m,q;
int main()
{
    opti
    
        cin>>n;
        ll a[n+1];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll maxi = 0;
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(a[i] >= maxi){
                ans++;
                maxi = a[i];
            }
        }
        cout<<ans<<endl;
    return 0;
}
