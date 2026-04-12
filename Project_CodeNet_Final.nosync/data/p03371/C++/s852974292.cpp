#include<iostream>
using namespace std;
int main(){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	if(c*2<a+b){
		if(x<y){
			if(c*2<b){
				cout << c*2*y << "\n";
			}
			else{
				cout << c*2*x+b*(y-x) << "\n";
			}
		}
		else{
			if(c*2<a){
				cout << c*2*x << "\n";
			}
			else{
				cout << c*2*y+a*(x-y) << "\n";
			}
		}
	}
	else{
		cout << a*x+b*y;
	}
	return 0;
}
