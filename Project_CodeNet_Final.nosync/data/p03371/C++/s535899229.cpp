#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	if((a+b)<=2*c){
		cout <<(a*x+b*y) <<endl;
	}
	else if(x==y){
		cout <<(2*(x*c)) <<endl;
	}
	else if(x>y){
		if(a>=2*c){
			cout << (2*(x*c)) << endl;
		}
		else{
			cout << (2*(y*c)+(x-y)*a) << endl;
		}
	}
	else{
		if(b>=2*c){
			cout << (2*(y*c)) << endl;
		}
		else{
			cout << (2*(x*c)+(y-x)*b) << endl;
		}
	}
	return 0;
}