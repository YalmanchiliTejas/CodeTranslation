#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
using namespace std;
const int N=105;
string s;
ll ans=0,cheng;
int n,k,c[N];
vi v;
ll dfs(int now,int cnt,bool f)
{
//	cout<<now<<' '<<cnt<<' '<<f<<endl;
	if(cnt==k)return 1;if(now>=n)return 0;
	if(f)
	{
		ll res=0;
		for(int i=now;i<n;i++)
		{
			res+=dfs(i+1,cnt+1,f);
		}
		return res*9;
	}
	else
	{
		ll res=0;
		if(cnt+1!=k)
		{
			if(s[v[cnt+1]]=='0')res=0;
			else res=dfs(v[cnt+1],cnt+1,f);
		}else if(s[now]!='0')res=1;
		res+=dfs(v[cnt]+1,cnt,!f);
		res+=dfs(v[cnt]+1,cnt+1,!f)*max(s[now]-'0'-1,0);
		return res;
	}
}
int main()
{
	cin>>s>>k;
	n=s.size();
	v.clear();
	if(s=="0")
	{
		cout<<"0\n";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]!='0')
		{
			v.pb(i);
		}
	}
	while(v.size()<k)v.pb(v[v.size()-1]+1);
	if(v[v.size()-1]>=s.size())
	{
		puts("0");
		return 0;
	}
	cout<<dfs(v[0],0,0)<<endl;
	return 0;
}