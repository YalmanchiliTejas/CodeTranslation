#include<iostream>
using namespace std;
using ll = long long;
int main(){
	ll a,b,c,x,y,ans;
	cin >> a >> b >> c >> x >> y;
	if((a+b)>=2*c){
		if(x>=y){
			ans = min(y*2*c+(x-y)*a,x*2*c);
		}
		else{
			ans = min(x*2*c+(y-x)*b,y*2*c);
		}
		cout << ans << endl;
	}
	else{
		cout << a*x+b*y << endl;
	}
	return 0;
}