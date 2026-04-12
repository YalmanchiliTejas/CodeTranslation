#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;
const int inf=(1<<30);
#define rep(i,a,n)	for(int i=a;i<n;i++)
#define rrep(i,a,n) for(int i=(a-1);i>=n;i--)
	
int main(){
	ll n;
	cin>>n;
	ll a[n];
	a[0]=0;
	rep(i,1,n+1)cin>>a[i];
	ll h=0;
	ll ans=0;
	rep(i,1,n+1){
		if(h<=a[i]){
			ans++;
			h=max(h,a[i]);
		}
	}
	cout<<ans<<endl;
}