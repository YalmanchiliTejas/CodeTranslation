#include <iostream>
using namespace std;
int min(int a,int b){
    if(a>b) return b;
    else return a;
}

int main(){
    int a,b,c,x,y,t,res;
    cin >> a >> b >> c >> x >> y;
    if((a+b)<=2*c) res=x*a+y*b;
	else{
		if(x>y){
			t=2*c*y+a*(x-y);
			res=min(t,2*c*x);
		} 
		else{
			t=2*c*x+b*(y-x);
			res=min(t,2*c*y);
		} 
	}
	cout<< res;
    return 0;
}