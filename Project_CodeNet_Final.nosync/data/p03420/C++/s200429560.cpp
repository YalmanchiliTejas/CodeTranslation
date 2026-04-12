#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;

const int maxn=1e4+5;
const ll INF=0x3f3f3f3f;
ll n,k;
int main(){
	cin>>n>>k;
	ll ans=0;
	for (ll b=n;b>k;b--){
		ll l=k,r=b-1;
		
		ll c=(n+1)/b;
		
		ans+=c*(r-l+1);
		if (l==0) ans--;
		
		l=k+c*b;
		if (l<=n){
			ans+=n-l+1;
		}
		
//		cout<<ans<<endl;
	}
	
	cout<<ans;
}