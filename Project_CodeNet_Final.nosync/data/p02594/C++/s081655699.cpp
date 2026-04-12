#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
#define l long long
#define pb push_back
#define mem(a,n) memset(a,n,sizeof(a))
#define find(v,n) find(v.begin(),v.end(),n)
#define sort1(v) sort(v.begin(),v.end())
#define lb(v,n) lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n) upper_bound(v.begin(),v.end(),n)-v.begin()
#define mod 1000000007
#define reverse(s) reverse(s.begin(),s.end())
//#define pi pair<l,l> 
const double pi=3.141592653589793;
bool isprime(l n)
{
	for(l i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
/*bool fact(l n)
{
	vector<l> v;
	for(l i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(i%2==1||(n/i)%2==1)
			{
				return true;
			}
		}
	}
	return false;
}*/
/*l power(l a,l b)
{
	l ans=1;
	while(b>0)
	{
		if(b&1)
		{
			ans=(ans*a);
		}
		b>>=1;
		a=(a*a);
	}
	return ans;
}//prefixsums*/
/*vector<vector<l> > c(100000);
void dfs(vector<l> v[],l root,bool vis[])
{
	vis[root]=true;
	//cout<<root<<"\n";
	for(l i=0;i<v[root].size();i++)
	{
		if(vis[v[root][i]]==false)
		{
			c[root].pb(v[root][i]);
			dfs(v,v[root][i],vis);
		}
	}
}*/
void frooty()
{
	int x;
	cin>>x;
	if(x>=30)
		cout<<"Yes"<<"\n";
	else
		cout<<"No"<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q=1;
	//cin>>q;
	//q++;
	for(int i=0;i<q;i++)
	{
		frooty();
	}
}