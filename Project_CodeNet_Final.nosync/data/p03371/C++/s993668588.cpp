#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a,b,c,x,y,ans=0;
	cin >> a >> b >> c >> x >> y;
	
	if(x>y){
		swap(x,y); swap(a,b);
	}
	if(a+b>c*2){
		ans+=c*2*x;
		if(b>c*2){
			ans+=c*2*(y-x);
		}else{
			ans+=b*(y-x);
		}
	}else{
		ans+=a*x+b*y;
	}
	cout << ans;
}