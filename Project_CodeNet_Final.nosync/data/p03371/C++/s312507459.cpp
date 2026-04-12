#include<iostream>
using namespace std;

int main(){
	int a,b,c,x,y;
	long long ans;

	cin >>a >>b >>c >>x >>y;
	
	if(x==0&&b>2*c)ans=c*2*y;
	else if(y==0&&a>2*c)ans=c*2*x;
	else if(a+b>=c*2){
		if(x>=y){
			if((x-y)*2*c<=(x-y)*a)ans=c*2*x;
			else ans=c*2*y+a*(x-y);
		}
		else {
			if((y-x)*2*c<=(y-x)*b)ans=c*2*y;
			else ans=c*2*x+b*(y-x);
		}
	}
	else ans=a*x+b*y;

	cout<<ans<<endl;
	return 0;
}