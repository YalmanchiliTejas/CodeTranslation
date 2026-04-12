#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define inf 1e15
#define mod 1000000007

#define N 300005

string s;
ll n,m,x,y,d,k;
ll a[N];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int t=1;
//	cin>>t;
	while(t--){
	    
	    
	    cin>>n;
	    ll prefix[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    prefix[n-1]=a[n-1];
	    
	    for(int i=n-2;i>=0;i--){
	        prefix[i]=(prefix[i+1]+a[i])%mod;
	    }
	    
	    
	    ll ans=0;
	    
	    for(int i=0;i<n;i++){
	        
	        ans=(ans+(a[i]*((prefix[i]-a[i]+mod)%mod)%mod))%mod;
	    }
	    
	    
	    cout<<ans<<"\n";
	    
	    
	}
	return 0;
}
