#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int mex=100005;
#define ll long long 
#define test int t;cin>>t;while(t--)
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,a,n) for(int i=a;i<n;i++)
#define rfo(i,a,b) for(int i=a;i>=b;i--)
#define bg begin()
#define en end()
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define veci vector<int>
#define veclli vector<long long int> 
#define all(x) x.begin(),x.end()
#define sci(x) scanf("%d",&x);
#define scc(x) scanf("%c",&x);
#define scs(x) scanf("%s",x);
#define debug(arr,n) for(int i=0;i<n;i++) printf("%d ",arr[i]);
#define sz(x) x.size()
#define loop(x) for(auto it=x.begin();it!= x.end();it++) 


ll int power(ll int a,ll int b)
{
    ll int ans=1,f=a;
    while(b)
    {
        if(b&1ll) ans=(ans*f)%mod;
        b=b>>1ll;
        f=(f*f)%mod;
    }
    return ans;
}


int main()
{
  
    int n;
    cin>>n;
    ll int a[n],cf[n]={0},ans=0;
    fo(i,0,n)
    {cin>>a[i];
    cf[i]=a[i];
    }
    rfo(i,n-2,0)
   { cf[i]+=cf[i+1];
   cf[i]%=mod;
   }
    fo(i,0,n-1)
    {
        ans=(ans+(a[i]*cf[i+1])%mod)%mod;
    }
    
    cout<<ans<<endl;

}