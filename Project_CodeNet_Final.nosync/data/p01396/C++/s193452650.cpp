#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

class Edge
{
public:
    int to, cap, rev;
    Edge(){};
    Edge(int to0, int cap0){to = to0; cap = cap0;}
    Edge(int to0, int cap0, int rev0){to = to0; cap = cap0; rev = rev0;}
};

int maxFlow(const vector<vector<Edge> >& edges0, int source, int sink)
{
    static vector<vector<Edge> > edges;
    static vector<unsigned> index;
    static vector<int> level;
    static int n;

    class Func{
    public:
        static void bfs(int s){
            level.assign(n, -1);
            queue<int> q;
            level[s] = 0;
            q.push(s);
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for(unsigned i=0; i<edges[v].size(); ++i){
                    Edge& e = edges[v][i];
                    if(e.cap > 0 && level[e.to] < 0){
                        level[e.to] = level[v] + 1;
                        q.push(e.to);
                    }
                }
            }
        }
        static int dfs(int s, int t, int f){
            if(s == t)
                return f;
            for(unsigned& i=index[s]; i<edges[s].size(); ++i){
                Edge& e = edges[s][i];
                if(e.cap > 0 && level[s] < level[e.to]){
                    int g = dfs(e.to, t, min(f, e.cap));
                    if(g > 0){
                        e.cap -= g;
                        edges[e.to][e.rev].cap += g;
                        return g;
                    }
                }
            }
            return 0;
        }
    };

    n = edges0.size();
    edges.assign(n, vector<Edge>());
    for(int i=0; i<n; ++i){
        for(unsigned j=0; j<edges0[i].size(); ++j){
            const Edge& e = edges0[i][j];
            edges[i].push_back(Edge(e.to, e.cap, edges[e.to].size()));
            edges[e.to].push_back(Edge(i, 0, edges[i].size()-1));
        }
    }

    int ret = 0;
    for(;;){
        Func::bfs(source);
        if(level[sink] < 0)
            return ret;
        index.assign(n, 0);
        int f;
        while((f = Func::dfs(source, sink, INT_MAX)) > 0)
            ret += f;
    }

    return 0;
}

int coverNode(vector<vector<int> > dag)
{
    int n = dag.size();
    vector<vector<Edge> > edges(2*n+2);
    for(int i=0; i<n; ++i){
        edges[0].push_back(Edge(i+2, 1));
        edges[i+n+2].push_back(Edge(1, 1));
    }
    for(int i=0; i<n; ++i){
        for(unsigned j=0; j<dag[i].size(); ++j){
            edges[i+2].push_back(Edge(dag[i][j]+n+2, 1));
        }
    }
    return n - maxFlow(edges, 0, 1);
}

bool solve(vector<vector<int> > a)
{
    int h = a.size();
    int w = a[0].size();
    sort(a.rbegin(), a.rend());
    a.insert(a.begin(), vector<int>(a[0].begin(), a[0].end()));
    ++ h;

    vector<vector<int> > dag(h);
    for(int i=0; i<h; ++i){
        for(int j=i+1; j<h; ++j){
            bool ok = true;
            for(int k=0; k<w; ++k){
                if(a[i][k] <= a[j][k])
                    ok = false;
            }
            if(ok)
                dag[i].push_back(j);
        }
    }

    return coverNode(dag) == 2;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int> > a(h, vector<int>(w));
    vector<vector<int> > b(w, vector<int>(h));
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }

    if(solve(a) && solve(b))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}