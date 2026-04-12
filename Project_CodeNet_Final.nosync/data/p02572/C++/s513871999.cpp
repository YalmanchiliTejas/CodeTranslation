// In the name of god
#include <bits/stdc++.h>
#pragma GCC optimize("02")
#define F first
#define S second 
#define pb push_back
#define all(x) x.begin(),x.end()
#define fileoi freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;
using ll = long long;
const ll maxn=2e5+5,inf=1e18+18,mod=1e9+7;
ll n,a[maxn],ps[maxn],sum,ans;
int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ps[i]=a[i];
		if(i>0)ps[i]=(ps[i]+ps[i-1])%mod;
	}
	for(int i=0;i<n-1;i++){
		ll x=(ps[n-1]-ps[i]+mod)%mod;
		ans=(ans+((x*a[i])%mod))%mod;
	}
	cout<<ans%mod<<endl;
}
