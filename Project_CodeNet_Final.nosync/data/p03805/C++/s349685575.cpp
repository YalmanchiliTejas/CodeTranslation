#include <iostream>
#include <vector>
using namespace std;

class Edge
{
	public:
	int to,cost;
	Edge(int t,int c)
	{
		to=t;
		cost=c;
	}
};

vector<Edge> g[8];

int saiki(int now,int past,int n)
{
	int ret=0;
	for(int i=0;i<g[now].size();i++)
	{
		Edge e=g[now][i];
		if((past&(1<<e.to))==0)
			ret+=saiki(e.to,past|(1<<e.to),n);
	}
	if(past==(1<<n)-1)
		ret++;
	return ret;
}

int main()
{
	int n,m;
	int ans=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(Edge(b,1));
		g[b].push_back(Edge(a,1));
	}
	cout<<saiki(0,1,n)<<endl;
	return 0;
}