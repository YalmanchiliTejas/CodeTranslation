#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
 
	if (c*2>=a+b){
		cout << a*x + b*y << endl;
	}else {
		int ans = min(x,y)*2*c;
		if (x>y && a<=2*c){
			ans += (x-y)*a;
		}else if (x>y){
			ans += (x-y)*c*2;
		}else if (x<y && b<=2*c){
			ans += (y-x)*b;
		}else if (x<y){
			ans += (y-x)*c*2;
		}
		cout << ans << endl;
	}
 
//	printf("%.4f\n",ans);
}