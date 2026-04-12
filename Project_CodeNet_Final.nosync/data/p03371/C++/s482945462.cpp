#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int  fun=0;
	if(a+b>2*c)
		fun=1;
	else 
		fun=2;
	ll ans=0;
	if(fun==1)
	{
		ll ans1=0;
		if(x>=y){
			ans=y*2*c+(x-y)*a;
			ans1=x*2*c;
			ans=min(ans1,ans);
		}
		else{
			ans=x*2*c+(y-x)*b;
			ans1=y*2*c;
			ans=min(ans1,ans);
		} 
	}
	else
	{
		ans=x*a+y*b;
	}
	cout<<ans<<endl;
	return 0;
}