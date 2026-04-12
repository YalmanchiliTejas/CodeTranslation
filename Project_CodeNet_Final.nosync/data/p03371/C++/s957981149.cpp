#include<bits/stdc++.h>
using namespace std;
long long a,b,c,x,y,ans,T;
int main()
{
	cin>>a>>b>>c>>x>>y;
	ans+=min(x,y)*min(a+b,2*c);
	T=min(x,y);x-=T;y-=T;
	if(y)a=b,x=y;
	ans+=x*min(2*c,a);
	cout<<ans<<endl;
}