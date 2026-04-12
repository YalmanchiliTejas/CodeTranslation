#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//O(F|E|)
class FordFulkerson{
public:
	class edge{
	public:
		int to, cap, rev;
		edge(){};
		edge(int _to, int _cap, int _rev){
			to = _to;
			cap = _cap;
			rev = _rev;
		}
	};
	vector<vector<edge> >G;
	vector<int>used;
	FordFulkerson(int n){
		G.resize(n);
	}
	void addEdge(int from, int to, int cap){
		G[from].push_back(edge(to, cap, G[to].size()));
		G[to].push_back(edge(from, 0, G[from].size() - 1));
	}
	int dfs(int v, int t, int f){
		if (v == t)return f;
		used[v] = 1;
		for (int i = 0; i < G[v].size(); i++){
			edge &e = G[v][i];
			if ((!used[e.to]) && (e.cap > 0)){
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	int maxFlow(int s, int t){
		int flow = 0;
		for (;;){
			used.clear();
			used.resize(G.size(), 0);
			int f = dfs(s, t, 1145141919);
			if (f == 0)return flow;
			flow += f;
		}
	}
};

int main(){
    for(int H, W, C, M, NW, NC, NM;cin>>H>>W>>C>>M>>NW>>NC>>NM;){
        if(H<0)break;
        FordFulkerson mf(310);
        for(int i=1;i<=H;i++)mf.addEdge(0, i, 1);
        for(int i=1;i<=H;i++)mf.addEdge(i, 301, 1);
        
        mf.addEdge(301, 302, NW);
        for(int i=51;i<=50+W;i++)mf.addEdge(i, i+50, 1);
        
        for(int i=101;i<=100+W;i++)mf.addEdge(i, 303, 1);
        
        mf.addEdge(303, 304, NC);
        for(int i=151;i<=150+C;i++)mf.addEdge(i, i+50, 1);
        for(int i=151;i<=150+C;i++)mf.addEdge(302, i, 1);
        
        for(int i=201;i<=200+C;i++)mf.addEdge(i, 305, 1);
        
        for(int i=251;i<=250+M;i++)mf.addEdge(304, i, 1);
        for(int i=251;i<=250+M;i++)mf.addEdge(i, 306, 1);
        mf.addEdge(305, 306, NM);

        for(int i=1;i<=W;i++){
            int n;
            cin>>n;
            for(int j=1;j<=n;j++){
                int h;
                cin>>h;
                mf.addEdge(h, 50+i, 1);
            }
        }
        for(int i=1;i<=C;i++){
            int n;
            cin>>n;
            for(int j=1;j<=n;j++){
                int w;
                cin>>w;
                mf.addEdge(100+w, 150+i, 1);
            }
        }
        for(int i=1;i<=M;i++){
            int n;
            cin>>n;
            for(int j=1;j<=n;j++){
                int c;
                cin>>c;
                mf.addEdge(200+c, 250+i, 1);
            }
        }
        cout << mf.maxFlow(0, 306) << endl; 
    }
	return 0;
}
