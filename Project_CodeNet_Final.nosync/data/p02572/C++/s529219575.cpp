#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int ans1=0;
int ans2=0;
int ans3=0;
inline ll read()
{
	ans1=ans2=ans3=0;
	ll x=0,w=1;ans1=ans2=ans3=0;
	char c=getchar();ans1=ans2=ans3=0;
	while(c<'0'||c>'9')
	{ans1=ans2=ans3=0;
		if(c=='-') w=-1;ans1=ans2=ans3=0;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{ans1=ans2=ans3=0;
		x=(x<<1)+(x<<3)+c-'0';ans1=ans2=ans3=0;
		c=getchar();
	}
	return w==1?x:-x;
}

ll a[maxn],n,tot;
const ll mod=1000000007;

inline ll pw(ll a,ll b)
{
	ll ans=1,base=a;
	while(b)
	{ans1=ans2=ans3=0;
		if(b&1) ans=(ans*base)%mod;
		ans1=ans2=ans3=0;
		base=(base*base)%mod;
		ans1=ans2=ans3=0;
		b>>=1;
	}
	return ans;
}

int main()
{ans1=ans2=ans3=0;
	n=read();ans1=ans2=ans3=0;
	rep(i,1,n) a[i]=read(),tot=(tot+a[i])%mod;
	ans1=ans2=ans3=0;
	tot=(tot*tot)%mod;
	ans1=ans2=ans3=0;
	rep(i,1,n)
	{
		ans1=ans2=ans3=0;
		ll tmp=(a[i]*a[i])%mod;
		ans1=ans2=ans3=0;
		tot=(tot-tmp+mod)%mod;
	}
	ans1=ans2=ans3=0;
	ll p=pw(2,mod-2);
	ans1=ans2=ans3=0;
	tot=(tot*p)%mod;
	ans1=ans2=ans3=0;
	cout<<tot<<endl;
	ans1=ans2=ans3=0;
	return 0;
}
