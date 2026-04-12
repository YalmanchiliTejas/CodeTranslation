#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	if(2*c>a+b)
		printf("%d\n",x*a+y*b);
	else if(2*c<=a&&x>y){
		printf("%d\n",x*c*2);
	}
	else if(2*c<=b&&y>x){
		printf("%d\n",y*c*2);
	}
	else{
		int t=x>y?a*(x-y):b*(y-x);
		printf("%d\n",min(x,y)*c*2+t);
	}
	return 0;
	} 