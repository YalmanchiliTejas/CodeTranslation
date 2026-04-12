#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define ll long long
using namespace std;
inline ll read() 
{ 
    ll x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
ll cnt,n;
ll h[51];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	h[i]=read();
	while(1)
	{
		ll mx=0,mxid=0,sec=100000000000ll;
		for(int i=1;i<=n;i++)
		if(h[i]>mx)mx=h[i],mxid=i;
		for(int i=1;i<=n;i++)
		if(h[i]!=mx)sec=min(sec,h[i]);
		ll tmp=(mx-sec)/(n);
		if(tmp<=0)break;
		cnt+=tmp;
		for(int i=1;i<=n;i++)
		if(i!=mxid)h[i]+=tmp;
		h[mxid]-=tmp*n;
	}
	while(1)
	{
		int pd=0;
		for(int i=1;i<=n;i++)
		if(h[i]>=n){pd=1;break;}
		if(pd==0)break;
		ll mx=0,mxid=0;
		for(int i=1;i<=n;i++)
		if(h[i]>mx)mx=h[i],mxid=i;
		ll tmp=mx/n;
	 	cnt+=tmp;
		for(int i=1;i<=n;i++)
		if(i!=mxid)h[i]+=tmp;
		h[mxid]-=tmp*n;
	}
	printf("%lld\n",cnt);
}
/*
500000000000000000
*/