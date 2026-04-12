#include <bits/stdc++.h>
using namespace std;
#define ALL(v) v.begin(),v.end()
#define UN(v) sort(ALL(v)),v.erase(unique(ALL(v)))
#define FILL(x,y) memset(x,y,sizeof(x))
#define EACH(v,it) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
int n,ans;
pii x[100005],y[100005];
int root[100005];
int cnt;
struct State
{
	int x;
	int y;
	int w;
	State(int x,int y,int w):x(x),y(y),w(w){}	
};
vector<State> E;
/*---main code---*/

int find(int x)
{
	if(root[x]!=x)
	{
		root[x]=find(root[x]);
	}
	return root[x];
}

bool unite(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)
	{
		return 0;
	}
	root[x]=y;
	return 1;
}

bool cmp(State x,State y)
{
	return x.w<y.w;
}

int main()
{
	FIO;
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++)
	{
		root[i]=i;
		cin>>x[i].first>>y[i].first;
		x[i].second=y[i].second=i;
	}
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	for(int i=n;i>1;i--)
	{
		E.push_back(State(x[i].second,x[i-1].second,x[i].first-x[i-1].first));
		E.push_back(State(y[i].second,y[i-1].second,y[i].first-y[i-1].first));
	}
	sort(ALL(E),cmp);
	for(int i=0;i<E.size();i++)
	{
		if(unite(E[i].x,E[i].y))
		{
			ans+=E[i].w;
			cnt--;
			if(cnt==1)
			{
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
