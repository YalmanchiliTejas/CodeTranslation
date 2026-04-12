#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,s[maxn],vis[maxn];
vector <int> vec;

int main()
{
	n=read(); ll ans=0;
	for(int i=0;i<n;i++) s[i]=read();
	for(int i=1;i<(n+1)/2;i++)
	{
		ll tmp=0; vec.clear();
		for(int j=i;j<n;j+=i)
		{
			if(vis[n-1-j]||vis[j]||j==n-1-j||n-1-j<i) break;
			tmp+=s[j]; tmp+=s[n-j-1]; vis[j]=1; vis[n-j-1]=1;
			vec.push_back(j); vec.push_back(n-j-1);
			ans=max(ans,tmp);
		}
		for(int j=0;j<vec.size();j++) vis[vec[j]]=0;
	}
	cout<<ans<<endl;
	return 0;
}