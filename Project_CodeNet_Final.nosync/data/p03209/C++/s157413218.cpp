#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=55;
ll level,n,h[N],p[N];
inline ll solve(ll x,ll y)
{
	if(x==0)return 1;
	if(y==1)return 0;
	if(y>1&&y<=h[x-1]+1)//在第一层 
		return solve(x-1,y-1);//去掉第二层加上下面的 
	if(y==h[x-1]+2)return p[x-1]+1;//在中间 
	if(y>h[x-1]+2&&y<3+2*h[x-1])//在第二层 
		return p[x-1]+1+solve(x-1,y-2-h[x-1]);//去掉第一层+中间的+下面的 
	return p[x-1]*2+1;//最后正好 
}
int main()
{
	cin>>level;
	cin>>n;
	h[0]=1;
	p[0]=1;
	for(ll i=1;i<=level;i++)
	{
		h[i]=3+h[i-1]*2;
		p[i]=1+p[i-1]*2;
	}
	cout<<solve(level,n)<<endl;
	return 0;
}