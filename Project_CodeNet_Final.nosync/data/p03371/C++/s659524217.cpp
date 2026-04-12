#include"bits/stdc++.h"
using namespace std;
int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int s=min(x,y),ans=0;
	x-=s,y-=s;
	if(2*c<a+b)
		ans+=2*c*s;
	else
		ans+=(a+b)*s;
	if(x>0){
		if(2*c<a)
			ans+=2*c*x;
		else
			ans+=x*a;
	}
	if(y>0){
		if(2*c<b)
			ans+=2*c*y;
		else
			ans+=y*b;
	}
	cout<<ans;
}

