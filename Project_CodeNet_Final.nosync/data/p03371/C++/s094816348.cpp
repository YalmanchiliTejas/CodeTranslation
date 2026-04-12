#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
	c*=2;
	int n=max(x,y);
	ll ans;
	for(int i=0; i<=n; i++){
		ll t=a*x+b*y+c*i;
		ans=min(ans,t);
		if(x>0) x--;
		if(y>0) y--;
	}
	cout<<ans<<endl;
}