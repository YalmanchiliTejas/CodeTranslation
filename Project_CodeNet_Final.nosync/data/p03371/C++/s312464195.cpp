#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int ans1,ans2,ans3;
	ans1=max(x,y)*2*c;
	if(x>y){
		ans2=y*2*c;
		ans2=ans2+(x-y)*a;
	}
	else{
		ans2=x*2*c;
		ans2=ans2+(y-x)*b;
	}
	ans3=x*a+y*b;
	cout<<min(ans1,min(ans2,ans3));
}