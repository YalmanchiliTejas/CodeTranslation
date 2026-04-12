#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,int>pii;
//struct _IO { _IO() { ios::sync_with_stdio(0); cin.tie(0); } }_io;
const ll mod=1e9+7;
ll fpow(ll x,ll b){ ll res=1;for(;b;b>>=1){ if(b&1)res=res*x%mod; x=x*x%mod;} return res;}
int main(){
	int n;
	cin>>n;
	vector<ll>v(n);
	ll sum=0;
	for(auto &i:v) cin>>i,sum+=i;
	ll ans=0;
	sum=(sum-v[0]+mod)%mod;
	for(int i=0;i<n-1;i++){
		ans=(ans+sum*v[i]%mod)%mod;
		sum=(sum-v[i+1]+mod)%mod;
	}
	cout<<ans%mod<<'\n';
}