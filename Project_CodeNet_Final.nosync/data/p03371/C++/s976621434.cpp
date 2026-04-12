#include<iostream>
using namespace std;

int big (int a, int b ){
	if(a>b){
		return a;
	}
	return b;
}

int small (int a,int b){
	return a+b-big(a,b);
}


int main (){
	int a,b,c,x,y;
	int ans=0;


	cin >> a >> b >> c >> x >>y;
/*	
	if((a+b)> c * 2 ){
		ans = ans + small(x,y)*c;
		if(x>y){
			ans = ans + (x-y) * a;
		}
		else ans = ans + (y-x) * b;
	}
	else if(big(a,b)>=c*2){
		if(a>=b){
			if(x>=y){
				ans = c * 2 * x;
			}
			else ans = c*2*x+b*(y-x);
		}
	}
	else ans = a*x+b*y;
*/
	if((a+b)>=2*c){
		if(x>=y){
			ans = ans + c * y * 2;
			if(a>=2*c){
				ans = ans + 2*c*(x-y);
			}
			else ans = ans + a*(x-y);
		}
		else if(y>x){
			ans = ans + c * x * 2;
			if(b>=2*c){
				ans = ans + 2 * c * (y-x);
			}
			else ans = ans + b * (y-x);
		}
	}
	else ans = a*x+b*y;



	cout << ans << endl;


	return 0;
}