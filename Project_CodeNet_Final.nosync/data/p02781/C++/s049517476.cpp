/*by freesteed*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define pb push_back
#define fill(x,c) memset(x,c,sizeof(x))
#define fi first
#define se second
typedef long long ll;typedef pair<int,int> PII;const ll mod=1e9+7;const int N = 1e6+10;ll a[N];
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main() {
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	int k;
	cin>>s>>k;
	if(k==1){
		ll n = s.size();
		ll dig = s[0]-'0';
		cout<<(n-1)*9+dig;
	}else if(k==2){
		ll n = s.size();
		ll dig = s[0]-'0',ans=0;
		for(ll i=2;i<n;i++)
		ans+=81*(i-1);
		ans+=(dig-1)*(n-1)*9;
		ll i=1;
		while(i<n&&s[i]=='0')i++;
		if(i==n){
			cout<<ans;
		}else{
			cout<<ans+s[i]-'0'+(n-i-1)*9; 
		} 
	}else{
		ll n = s.size();
		if(n<3){
			cout<<0;
			return 0;
		}
		ll dig = s[0]-'0',ans=0;
		for(ll i=3;i<n;i++){
			ans+=9*9*9*(i-2)*(i-1)/2;
		}
		ans+=(dig-1)*(n-2)*(n-1)/2*81;
		ll i=1;
		while(i<n&&s[i]=='0')i++;
		if(i>=n-1){
			cout<<ans;
		}else{
			ans+=(s[i]-'0'-1)*(n-i-1)*9;
			ll j = i+1;
			while(j<n&&s[j]=='0')j++;
			if(j==n){
				;
			}else{
				ans+=s[j]-'0'+(n-j-1)*9;
			}
			if(n-i-1>=2){
				ans+=81*(n-i-1-1)*(n-i-1)/2;
			}
			cout<<ans;
		}
	}
  	return 0;
}

