#include<iostream>
using namespace std;
int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int a1=min(x*a+y*b,max(x,y)*c*2);
	if(x<y)
		a1=min(a1,x*c*2+(y-x)*b);
	if(x>y)
		a1=min(a1,y*c*2+(x-y)*a);
	cout<<a1<<endl;
	return 0;
}