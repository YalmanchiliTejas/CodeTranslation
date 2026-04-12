#include <iostream>
using namespace std;

int main(){
	/*input*/
	int a, b, c, x, y;	cin >> a >> b >> c >> x >> y;
	/*calculation*/
	int ans = 0;
	if(x >= y){
		if(a + b >= 2*c){
			ans+=y*2*c;
			if(a >= 2*c){
				ans+=2*c*(x - y);
			}else{
				ans+=a*(x - y);
			}
		}else{
			ans+=a*x+b*y;
		}
	}else{
		if(a + b >= 2*c){
			ans+=x*2*c;
			if(b >= 2*c){
				ans+=2*c*(y - x);
			}else{
				ans+=b*(y - x);
			}
		}else{
			ans+=a*x+b*y;
		}
	}
	/*output*/
	cout << ans << endl;
}
