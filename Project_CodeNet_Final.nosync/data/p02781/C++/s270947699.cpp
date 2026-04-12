//QWsin
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define out(i,u) for(int i=first[u];i!=-1;i=nxt[i])
#define repvc(i,vc) for(int i=0,Sz=vc.size();i<Sz;++i)
using namespace std;
inline int read()
{
	char ch=getchar();int ret=0,f=1;
	while(ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	for(;ch>='0' && ch<='9';ch=getchar()) ret=ret*10+ch-'0';
	return ret*f;
}

typedef long long ll;
const int INF=1<<30;

const int maxn=100+10;

int a[maxn],k,n;
char s[maxn];

ll Pow(ll x,int p){
	ll ret=1;
	rep(i,1,p) ret*=x;
	return ret;
}

ll C(int n,int m){
	if(n<0||m<0||n<m) return 0;
	ll ret=1;
	rep(i,0,m-1) ret*=(n-i);
	rep(i,1,m) ret/=i;
	return ret;
}


int main()
{
	scanf("%s%d",s+1,&k);
	n=strlen(s+1);
	rep(i,1,n) a[i]=s[i]-'0';
	rep(i,1,n/2) swap(a[i],a[n+1-i]);
	ll ans=C(n-1,k)*Pow(9,k);//最高位为0 
	int p1=n-1,p2;
	while(p1>=1 && a[p1]==0) --p1;
	p2=p1-1;
	while(p2>=1 && a[p2]==0) --p2;
	 
	if(k==1)
	{ 
		ans+=(a[n]);
	}
	if(k==2)
	{
		ans+=(a[n]-1)*C(n-1,k-1)*Pow(9,k-1);//最高位小 
		if(p1>0)ans+=1*C(p1-1,k-1)*Pow(9,k-1);
		if(p1>0)ans+=(a[p1]);//最高位一样 ，次高位不为0 
	}
	if(k==3)
	{
		ans+=(a[n]-1)*C(n-1,k-1)*Pow(9,k-1);//最高位小 
		if(p1>0)ans+=1*C(p1-1,k-1)*Pow(9,k-1);//最高位抵着，次高位为0 
		if(p1>0)ans+=(a[p1]-1)*(p1-1)*9;//最高位抵着，次高位小 
		if(p2>0)ans+=1*1*(p2-1)*9;//最高位抵着，次高位抵着，次次高位为0 
		if(p2>0)ans+=(a[p2]);	
	}
	cout<<ans<<endl;
	return 0;
}
