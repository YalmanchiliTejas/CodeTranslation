#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a,b,c,x,y,pa,pb,pc;
	cin>>a>>b>>c>>x>>y;
	pa=x*a+y*b;
	pc=(x>y?x:y)*c*2;
	
	if(x<=y)
		pb=(y-x)*b+x*c*2;
	else pb=(x-y)*a+y*c*2;
	
	int res=min(pa,min(pb,pc));
	cout<<res<<endl;
	return 0;
}