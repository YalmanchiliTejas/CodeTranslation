#include<bits/stdc++.h>
#define inf 1e9+7
#define ll long long
#define clr(c) memset(c,0,sizeof(c))
const int M=2e5+10;
const int N=1e5+10;
using namespace std;
inline ll read()
{
	ll sum=0,b=1; char c=getchar();
	while(!isdigit(c)){if(c=='-') b=-1; c=getchar();}
	while(isdigit(c)){sum=sum*10+c-48; c=getchar();}
	return b*sum;
}
ll n,m,b,k;
char s[110];
ll q_pow(ll x,ll y)
{
	ll t=x,res=1;
	while(y)
	{
		if(y&1) res=res*t;
		t*=t;
		y>>=1;
	}
	return res;
}
int main()	
{	
	ll i,j;
	scanf("%s",s+1);
	k=read();
	ll ans=0;
	ll len=strlen(s+1);
	ll l=0,r=0,rr=0;
	for(i=2;i<=len;i++)
	{
		if(s[i]!='0')
		{
			if(l==0) l=i;
			else if(r==0) r=i;
			else if(rr==0) {rr=i;break;}
		}
	}
	if(k==1)
	{
		ll x=s[1]-'0';
		ans=x+(len-1)*9;
	}
	else if(k==2)
	{
		if(len==1)
		{
			printf("0"); return 0;
		}
		ll x=s[1]-48,y=max(s[l]-48,0),z=max(s[r]-48,0);		
		ans=(x-1)*9*(len-1)+81*(len-1)*(len-2)/2;//最高位为0  
		if(l>0)
		{
			ans+=y;//最高位不变，次高位乱选			
			ans+=9*(len-l);
		}
	}
	else if(k==3)
	{
		if(len<3)
		{
			printf("0"); return 0;
		}
		ll x=s[1]-48;
		ll y=max(s[l]-48,0),z=max(s[r]-48,0),zz=max(s[rr]-48,0);		
		ans=(x-1)*81*(len-2)*(len-1)/2+81*9*(len-1)*(len-2)*(len-3)/6;//最高位为0 和小于 
		if(l>0)
		{
			if(r>0)
			{
				ans+=z+9*(len-r);
				//此高位同	
			}
			ans+=(y-1)*9*(len-l)+81*(len-l)*(len-l-1)/2;//此高位不同 
		}
	}
	
	
	printf("%lld",ans);
	return 0;
} 