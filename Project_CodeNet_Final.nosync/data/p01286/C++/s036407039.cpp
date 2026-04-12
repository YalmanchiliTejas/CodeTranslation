#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 9999999
#define SOUR 400
#define SINK 401
#define NW	 402
#define NC	 403
#define NM	 404
#define NW2	 405
#define NC2  406
#define NM2	 407

class Node
{
public:
	vector<int> to;
};

int flow[410][410],capa[410][410];

int dfs(int p, int T, int mf, vector<Node>& graph, vector<int>& level, vector<bool>& finished)
{
	if(p==T) return mf;
	if(finished[p]) return 0;
	
	finished[p]=true;
	
	for(int i=0; i<graph[p].to.size(); i++)
	{
		int next=graph[p].to[i], fw=capa[p][next]-flow[p][next];
		if(level[p] >= level[next]) continue;
		if(fw <=0 ) continue;
	
		int f=dfs(next, T, min(mf, fw), graph, level, finished);
		if(f>0)
		{
			finished[p]=false;
			flow[p][next]+=f;
			flow[next][p]-=f;
			return f;
		}
	}
	
	return 0;
}

int dinic(int S, int T, vector<Node>& graph)
{
	bool end=false;
	int total=0;
	while(!end)
	{
		end=true;
		vector<int> level(graph.size(), -1);
		level[S]=0;
		
		queue<int> q;
		q.push(S);
		while(!q.empty())
		{
			int n=q.front(); q.pop();
			for(int i=0; i<graph[n].to.size(); i++)
			{
				int next=graph[n].to[i];
				if(level[next]!=-1) continue;
				if(capa[n][next]-flow[n][next] <= 0) continue;
				level[next]=level[n]+1;
				q.push(next);
			}
		}
		
		if(level[T]==-1) break;
		
		vector<bool> finished(graph.size());
		while(1)
		{
			int fw=dfs(S, T, INF, graph, level, finished);
			if(fw<=0) break;
			
			total+=fw;
			end=false;
		}
	}
	
	return total;
}

void Connect(int u, int v, int w, vector<Node>& graph)
{
	graph[u].to.push_back(v);
	graph[v].to.push_back(u);
	capa[u][v]+=w;
	capa[v][u]+=w;
	
	flow[v][u]+=w;
}

int main()
{
	int N[7];
	while(scanf("%d%d%d%d%d%d%d", &N[0],&N[1],&N[2],&N[3],&N[4],&N[5],&N[6]))
	{
		if(N[0]<0&&N[1]<0&&N[2]<0&&N[3]<0&&N[4]<0&&N[5]<0&&N[6]<0) break;
		
		memset(flow,0,sizeof(flow));
		memset(capa,0,sizeof(capa));
		vector<Node> graph(410);
		
		Connect(NW, NW2, N[4], graph);
		Connect(NC, NC2, N[5], graph);
		Connect(NM, NM2, N[6], graph);
		
		for(int i=0; i<N[0]; i++)
		{
			Connect(SOUR, 50*0+i, 1, graph);
			Connect(50*1+i,NW, 1, graph);
			Connect(50*0+i, 50*1+i, 1, graph);
		}
		
		for(int i=0; i<N[1]; i++)
		{
			Connect(50*3+i, NC, 1, graph);
			Connect(50*2+i, 50*3+i, 1, graph);
		}
		
		for(int i=0; i<N[2]; i++)
		{
			Connect(NW2, 50*4+i, 1, graph);
			Connect(50*5+i, NM, 1, graph);
			Connect(50*4+i, 50*5+i, 1, graph);
		}
		
		for(int i=0; i<N[3]; i++)
		{
			Connect(NC2, 50*6+i, 1, graph);
			Connect(50*7+i, SINK, 1, graph);
			Connect(50*6+i, 50*7+i, 1, graph);
		}
		Connect(NM2, SINK, N[6], graph);

		
		for(int i=1; i<4; i++)
		{
			for(int k=0; k<N[i]; k++)
			{
				int S,t;
				scanf("%d", &S);
				while(S--)
				{
					scanf("%d", &t); t--;

					Connect(50*((i-1)*2+1)+t, 50*(i*2)+k, 1, graph);

				}
			}
		}
		
		printf("%d\n", dinic(SOUR, SINK, graph));

	}
}