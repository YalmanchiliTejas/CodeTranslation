//Think simple yet elegant.
#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll  unsigned long long
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
const ll maxn=105;
const ll mod=1e9+7;

int main(){
	fast;
	ll n,i,j,k,ans=0;
	cin>>n;
	vector<ll> a(n+1),p(n+1);
	for(i=1;i<=n;++i){
		cin>>a[i];
		if(i>1){
			p[i]=p[i-1]+a[i];
		}
		else
		p[1]=a[1];
	}
	ll term;
	p[n]%=mod;
	for(i=1;i<=n;i++){
		p[i]%=mod;
		term=((a[i]*p[n])%mod-(a[i]*p[i])%mod+mod)%mod;
		ans=(ans+term+mod)%mod;
	}
	cout<<ans;
}