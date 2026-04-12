#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[110][110];

int main(){	
	ll a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	ll ans=0;
	if(a+b>2*c){
		if(x>y){
			ans+=y*2*c;
			x-=y;
			if(a>2*c){
				ans+=x*2*c;
			}else ans+=x*a;
		}else{
			ans+=x*2*c;
			y-=x;
			if(b>2*c){
				ans+=y*2*c;
			}else ans+=y*b;
		}
	}else ans+=x*a+y*b;
	cout<<ans;
	return 0;
}
