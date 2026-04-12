#include <bits/stdc++.h>

#define ll long long
#define rep(i,n) for(int i=0;(i)<n;i++)

using namespace std;

int main()
{
	ll a, b, c, x, y;
	cin>>a>>b>>c>>x>>y;
	if (a+b<=c*2){
		cout << a*x+b*y << endl;
	}else{
		ll ans=min(x,y)*c*2;
		if(x>y){
			if (2*c<a){
				ans+=2*c*(max(x,y)-min(x,y));
			}else{
				ans+=a*(max(x,y)-min(x,y));
			}
		}else{
			if (2*c<b){
				ans+=2*c*(max(x,y)-min(x,y));
			}else{
				ans+=b*(max(x,y)-min(x,y));
			}
		}
		cout << ans << endl;
	}
	return 0;
}