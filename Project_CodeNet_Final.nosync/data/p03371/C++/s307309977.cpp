#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a,b,c,x,y,ans=10000000001,x1,y1;
	cin>>a>>b>>c>>x>>y;
	for(ll i=0;i<100000001;i+=2){
		x1=i;
		if(x<=i/2)x1=2*x;
		y1=i;
		if(y<=i/2)y1=2*y;
		ans=min(ans,(i*c)+a*(x-x1/2)+b*(y-y1/2));
	}
	cout<<ans<<endl;
	return 0;
}

