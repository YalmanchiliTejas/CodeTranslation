#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=998244353;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,s;
    cin>>n>>s;
    ll a[n+1];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    ll ans=0;
    vector<ll> dp(s+1,0);
    for(int i=1;i<=n;i++){
    	for(int j=s-a[i];j>=0;j--){
    		dp[0]=i;
    		if(j==s-a[i]){
    			ans+=(dp[j]*(n-i+1))%mod;
    			ans%=mod;
    		}
    		else if(j==0){
    			dp[j+a[i]]+=i;
    		}
    		else dp[j+a[i]]+=dp[j];
    		dp[j+a[i]]%=mod;
    	}
    }
    cout << ans<<endl;
    return 0;
}
