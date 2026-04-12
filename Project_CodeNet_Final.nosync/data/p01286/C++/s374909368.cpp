#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>
#include<random>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

// Dinic???:????°??????????,?????§???????????§??????
// ?????????: Dinic* dinic = new Dinic(V)??§?????????(V???????????°)
// dinic->add_edge?????????dinic->add_edge_both??§??????????????????dinic->max_flow??§?????§?????????????±???????
#define NG -1
#define SZ(a) ((int)((a).size()))
class Dinic
{
public:
    Dinic(int input_maxv) : maxv(input_maxv)
    {
        G.resize(input_maxv);
        level.resize(input_maxv);
        iter.resize(input_maxv);
    }

    void add_edge_both(int from, int to, int cap)
    {
        const int rev_from  = SZ(G[from]);
        const int rev_to    = SZ(G[to]);
        G[from].push_back(edge(to,cap,rev_to));
        G[to].push_back(edge(from,cap,rev_from));
    }

    void add_edge(int from, int to, int cap)
    {
        const int rev_from  = SZ(G[from]);
        const int rev_to    = SZ(G[to]);
        G[from].push_back(edge(to,cap,rev_to));
        G[to].push_back(edge(from,0,rev_from));
    }

    int max_flow(int s, int t)
    {
        int flow = 0;
        for(;;)
        {
            bfs(s);
            if(level[t]<0) break;
            fill(iter.begin(),iter.end(),0);
            int f;
            while( (f=dfs(s,t,DINIC_INF))>0)
            {
                flow += f;
            }
        }

        return flow;
    }

    vector <bool> get_nodes_in_group(int s)
    {
        vector <bool> ret(maxv);

        queue<int> que;
        que.push(s);
        while(!que.empty())
        {
            int v = que.front();
            que.pop();
            ret[v]=true;

            for(int i=0;i<SZ(G[v]);i++)
            {
                edge &e = G[v][i];
                if(e.cap>0 && !ret[e.to])
                {
                    que.push(e.to);
                }
            }
        }
        return ret;
    }

    void disp()
    {
        for (int v = 0; v < maxv; v++)
        {
            printf("%d:",v);
            for(int i=0;i<SZ(G[v]);i++)
            {
                if(G[v][i].init_cap>0)
                {
                    printf("->%d(%d),",G[v][i].to,G[v][i].init_cap);
                }
            }
            printf("\n");
        }
    }

private:
    void bfs(int s)
    {
        fill(level.begin(),level.end(),NG);
        queue<int> que;
        level[s]=0;
        que.push(s);
        while(!que.empty())
        {
            int v = que.front();
            que.pop();
            for(int i=0;i<SZ(G[v]);i++)
            {
                edge &e = G[v][i];
                if(e.cap>0 && level[e.to]<0)
                {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f)
    {
        if(v==t) return f;
        for (int &i=iter[v];i<SZ(G[v]);i++)
        {
            edge& e = G[v][i];
            if(e.cap>0 && level[v]<level[e.to])
            {
                int d = dfs(e.to, t, min(f, e.cap));
                if(d>0)
                {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    static const int DINIC_INF = INT_MAX;

    struct edge
    {
        edge(int input_to, int input_cap, int input_rev) : to(input_to), cap(input_cap), rev(input_rev), init_cap(input_cap) {}
        int to;
        int cap;
        int rev;
        int init_cap;
    };

    int maxv;
    vector < vector <edge> > G;
    vector < int > level;
    vector < int > iter;

};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
	int H, W, C, M, Nw, Nc, Nm;
	while (cin >> H >> W >> C >> M >> Nw >> Nc >> Nm) {
		if (H == -1) break;
		int s = H + 2 * (W + 1) + 2 * (C + 1) + 2 * (M + 1);
		int t = s + 1, V = t + 1;
		Dinic dinic(V);
		int w1 = H + W, w2 = w1 + W + 1;
		int c1 = w2 + C + 1, c2 = c1 + C + 1;
		int m1 = c2 + M + 1, m2 = m1 + M + 1;

		for (int i = 0; i < H; i++) {
			dinic.add_edge(s, i, 1);
			dinic.add_edge(i, w1, 1);
		}

		for (int i = 0; i < W; i++) {
			// ??? -> ???
			dinic.add_edge(H + i, w1 + 1 + i, 1);
			// ?¬????????????????????????????
			dinic.add_edge(w1 + 1 + i, c1, 1);
		}
		dinic.add_edge(w1, w2, Nw);
		
		for (int i = 0; i < C; i++) {
			// ??? -> ???
			dinic.add_edge(w2 + 1 + i, c1 + 1 + i, 1);
			// ?¬????????????????????????????
			dinic.add_edge(c1 + 1 + i, m1, 1);
			// ?????????????????????????????????
			dinic.add_edge(w2, w2 + 1 + i, 1);
		}
		dinic.add_edge(c1, c2, Nc);

		for (int i = 0; i < M; i++) {
			// ??? -> ???
			dinic.add_edge(c2 + 1 + i, m1 + 1 + i, 1);
			// ?????????????????????????????????
			dinic.add_edge(c2, c2 + 1 + i, 1);
			// t ???????????????
			dinic.add_edge(m1 + 1 + i, t, 1);
		}
		dinic.add_edge(m1, m2, Nm);
		dinic.add_edge(m2, t, Nm);

		for (int i = 0; i < W; i++) {
			int N;
			cin >> N;
			for (int j = 0; j < N; j++) {
				int h;
				cin >> h; h--;
				dinic.add_edge(h, H + i, 1);
			}
		}
		for (int i = 0; i < C; i++) {
			int N;
			cin >> N;
			for (int j = 0; j < N; j++) {
				int w;
				cin >> w; w--;
				dinic.add_edge(w + H, w2 + 1 + i, 1);
			}
		}
		for (int i = 0; i < M; i++) {
			int N;
			cin >> N;
			for (int j = 0; j < N; j++) {
				int c;
				cin >> c; c--;
				dinic.add_edge(c1 + 1 + c, m1 + 1 + i, 1);
			}
		}
		cout << dinic.max_flow(s, t) << endl;
	}
    return 0;
}