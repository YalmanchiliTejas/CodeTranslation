#include<bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue <ll> q;
ll n,x,Ans;
int main()
{
	scanf("%lld",&n);
	ll t=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		q.push(x);
	}
	while(q.top()+t>=n)
	{
		ll x=(q.top()+t)/n,y=(q.top()+t)%n;q.pop();
		Ans+=x;
		ll now=0;/*
		while(x>=n)
		{
			Ans+=(n-1)*x/n;
			now+=x/n*(n-1);
			x=x%n+x/n*(n-1);
		}*/
		//cout<<x<<endl;
		y+=now;
		t+=x;
		q.push(y-t);
		//cout<<y<<endl;
	}/*
	for (int i=1;i<=n;i++)
	{
		printf("%lld ",q.top()+t);q.pop();
	}*/
	printf("%lld\n",Ans);
}