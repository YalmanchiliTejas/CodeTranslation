#include<iostream>
using namespace std;



int main (){
	int a,b,c,x,y;
	int ans=0;


	cin >> a >> b >> c >> x >>y;

	if((a+b)>=2*c){
		if(x>=y){
				ans += c*y*2 + min(2*c,a)*(x-y);
		}
		else if(y>x){
			ans += c*2*x + min(2 * c,b) * (y-x);
		}
	}
	else ans = a*x+b*y;



	cout << ans << endl;


	return 0;
}