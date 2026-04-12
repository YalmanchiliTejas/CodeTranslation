#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    if(n&1){
    	ll ans=-1e18;
    	ll sum=0;
    	for(int i=0;i<n;i++){
    		if(i%2==0)sum+=a[i];
    	}
    	for(int i=0;i<n;i++){
    		if(i%2==0)ans=max(ans,sum-a[i]);
    	}

    	ll dp[n];
    	dp[0]=0;
    	for(int i=1;i<n;i++){
    		if(i%2==0)dp[i]=dp[i-1];
    	    else{
    	    	ll num=a[i]-a[i-1];
    	    	dp[i]=max(dp[i-1]+num,0LL);
    	    }
    	}
    	ll m=-1e18;
    	for(int i=0;i<n;i++){
    		if(i&1){
    			dp[i]-=a[i+1];
    			m=max(dp[i],m);
    		}
    	}
    	ans=max(ans,sum+m);
    	cout << ans <<endl;
    }
    else{
    	ll b[n+1];
    	b[n]=0;
    	for(int i=n-1;i>=0;i--){
    		if(i&1)b[i]=b[i+1]+a[i];
    		else b[i]=b[i+1];
    	}
    	ll sum=0;
    	ll ans=-1e18;
    	for(int i=0;i<n-1;i++){
    		if(i%2==0)ans=max(ans,sum+b[i+1]),sum+=a[i];
    	}
        ans=max(ans,sum);
        cout << ans <<endl;
    }
    return 0;
}
