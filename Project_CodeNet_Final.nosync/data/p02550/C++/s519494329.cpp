#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,x,m;

int a,b;

int cal(int x)
{
	return x*x%m;
}
int ans,s;

signed main()
{
	cin>>n>>x>>m;
	a=x,b=x;
	a=cal(a),b=cal(cal(b));
	while(a!=b)		//aÌøÒ»²½  bÌøÁ½²½ 
	{
		a=cal(a);
		b=cal(cal(b));
	}
	a=x;
	int cnt=1;
	while(a!=b)
	{
		a=cal(a);
		b=cal(b);
	}
	
	s+=b;
	b=cal(b);
	
	while(b!=a)
	{
		cnt++;
		s+=b;
		b=cal(b);
	}
	int cnt2=0;
	for(int i=x;i!=a;)
	{
		cnt2++;
		ans+=i;
		if(cnt2==n)	break;
		i=cal(i);
	}
	if(cnt2==n)
	{
		cout<<ans<<endl;
		return 0;
	}
	int p=n-cnt2;
	ans+=s*(p/cnt);
	p=p%cnt;
	for(int i=1;i<=p;i++)
	{
		ans+=a;
		a=cal(a);
	}
	cout<<ans<<endl;
}