#include<bits/stdc++.h>
using namespace std;

#define cst() int __t;scanf("%d",&__t);while(__t--)
#define rep(i,s,e) for(int i=s;i<e;++i)
#define repb(i,s,e) for(int i=s;i<=e;++i)
#define lep(i,s,e) for(int i=s;i>e;--i)
#define lepb(i,s,e) for(int i=s;i>=e;--i)
#define mst(a,b) memset(a,b,sizeof(a))
#define mcpy(des,sor) memcpy(des,sor,sizeof(sor))
#define pow2(x) ((x)*(x))
#define pt(x) cout<<#x<<"="<<x<<endl;


#define maxn 100006

typedef long long ll;
const int inf = 0x3f3f3f3f;

typedef pair<int,int> pii;

set<int> N[maxn];

int main()
{
	int n,a,b;
	queue<int> q;
	set<int> s;
	cin>>n;
	repb(i,1,n-1)
	{
		cin>>a>>b;
		N[a].insert(b);
		N[b].insert(a);
	}
	repb(i,1,n)
	{
		s.insert(i);
		if(N[i].size()==1)q.push(i);
	}
	while(!q.empty())
	{
		a=q.front();q.pop();
		if(s.find(a)==s.end())continue;
		for(auto u:N[a])if(N[u].size()<=2)
		{
			s.erase(a);s.erase(u);
			for(auto v:N[u])if(v!=a)
			{
				N[v].erase(u);
				if(N[v].size()==1)q.push(v);
				else if(N[v].size()==2)
				{
					for(auto b:N[v])if(N[b].size()==1)q.push(b);
				}
			}
		}
	}
	if(s.size()==0)cout<<"Second"<<endl;
	else cout<<"First"<<endl;

}
