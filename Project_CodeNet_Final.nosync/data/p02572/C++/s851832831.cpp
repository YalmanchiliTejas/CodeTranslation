#include <bits/stdc++.h>
#include <queue>
#define ll long long int
#define inf 3e18+1
#define all(v) (v).begin(),(v).end() 
#define N 200005
#define F first
#define S second
using namespace std;
ll mod=1e9+7;
int main()
{
    // added the two lines below 
    ios_base::sync_with_stdio (false); 
    cin.tie(NULL);
    cout.tie(0);    
  
    ll test=1;//cin>>test;
    while(test--){
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll pre[n];
        pre[0]=a[0];
        for(int i=1;i<n;i++) {
            pre[i]=(a[i]+pre[i-1])%mod;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+(a[i]*(pre[n-1]-pre[i]+mod)%mod)%mod)%mod;
        }
        cout<<ans<<endl;

        
    }
    return 0;
}


