#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mxx=1e9+7;

int main()
{
    fast
   
    int n;
    cin>>n;
    ll tot=0,ans=0;
    ll a[n];
    for(int i=0;i<n;i++)
    {
    	 cin>>a[i];
    	 tot+=a[i];
    }

    for(int i=0;i<n;i++)
    {    
    	tot-=a[i];
    	ans+=((tot%mxx)*(a[i]%mxx))%mxx;
    	ans%=mxx;
    }
    cout<<ans;
   
}