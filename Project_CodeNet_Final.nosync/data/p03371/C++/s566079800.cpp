#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,x,y;
	long long res=0,temp=0;
	cin>>a>>b>>c>>x>>y;
	res=a*x+b*y;
	if(x>y){
		temp=c*2*x;
		if(temp<res)res=temp;
	}else{
		temp=c*2*y;
		if(temp<res)res=temp;
	}
	if(x>y){
		temp=c*2*y;		
		x-=y;
		y=0;
		temp+=x*a;
		if(temp<res)res=temp;
	}else{
		temp=c*2*x;
		y-=x;
		x=0;
		temp+=y*b;
		if(temp<res)res=temp;
	}
	cout<<res<<endl;
	return 0;
}