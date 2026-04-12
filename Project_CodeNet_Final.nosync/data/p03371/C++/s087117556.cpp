#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int minx=0x3fffffff;
	int num=a*x+b*y;
	if(minx>num) minx=num; 
	int num1=min(x,y)*c*2;
	if(x>y) num1+=a*(x-y);
	else num1+=b*(y-x);
	if(minx>num1) minx=num1; 
	int num2=max(x,y)*2*c;
	if(minx>num2) minx=num2; 
	cout<<minx<<endl;
//	cout<<num<<" "<<num1<<" "<<num2; 
	return 0;
} 