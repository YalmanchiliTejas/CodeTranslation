#include<bits/stdc++.h>                          
using namespace std;
int a,b,c,x,y;
long long ans;
int main(){
	cin>>a>>b>>c>>x>>y;
	if(c*2<a+b)
	{
		ans+=min(x,y)*c*2;
		if(x>y) ans+=(x-y)*a;
		else ans+=(y-x)*b;
	}
	else ans=x*a+y*b;
	if(c*2*max(x,y)<ans) ans=c*2*max(x,y);
	cout<<ans;
	return 0;
}