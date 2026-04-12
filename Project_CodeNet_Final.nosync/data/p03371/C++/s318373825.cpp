#include <bits/stdc++.h>

#define ll long long int
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	ll a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	ll minus;
	ll ans=0;
	if(a>c*2 && b>c*2){
		ans += max(x,y) * c * 2;
	}else if(a>c*2){
		ans += x * c * 2;
		y -= x;
		if(y>0) ans += y * b;
	}else if(b>c*2){
		ans += y * c * 2;
		x -= y;
		if(x>0) ans += x * a;
	}else if(a+b > c*2){
		minus = min(x,y);
		ans += minus * c * 2;
		x -= minus;
		y -= minus;
		ans += a * x + b * y;
	}else ans += a*x+b*y;
	cout << ans << endl;
}
