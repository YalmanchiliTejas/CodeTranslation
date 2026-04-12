#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],pre[maxn],q;
map <ll,int> p;

int main()
{
	ll n,x,m; cin>>n>>q>>m; a[1]=q; pre[1]=a[1]; p[a[1]]=1;
	for(int i=2;i<=n;i++)
	{
		a[i]=(a[i-1]*a[i-1])%m;
		if(p[a[i]])
		{
			int x=p[a[i]];
			
			
			ll tmp=(n-i+1)/(i-x);
			ll ans=pre[i-1];
			ll p2=pre[i-1]-pre[x-1];
			ans+=p2*tmp;
			
			tmp=(n-i+1)%(i-x);
			ans+=pre[x+tmp-1]-pre[x-1];
			
			cout<<ans<<endl;
			return 0;
		}
		p[a[i]]=i;
		pre[i]=pre[i-1]+a[i];
	}
	cout<<pre[n]<<endl;
	return 0;
}