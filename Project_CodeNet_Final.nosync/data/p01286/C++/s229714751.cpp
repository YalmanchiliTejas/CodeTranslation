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
    static vector<bool> used;

    class Func{
    public:
        static int dfs(int s, int t, int f){
            if(s == t)
                return f;
            used[s] = true;
            for(unsigned i=0; i<edges[s].size(); ++i){
                Edge& e = edges[s][i];
                if(!used[e.to] && e.cap > 0){
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

    int n = edges0.size();
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
        used.assign(n, false);
        int f = Func::dfs(source, sink, INT_MAX);
        if(f == 0)
            return ret;
        ret += f;
    }
}

int main()
{
    for(;;){
        vector<int> n(4), m(4, 0);
        for(int i=0; i<4; ++i)
            cin >> n[i];
        for(int i=1; i<4; ++i)
            cin >> m[i];

        if(n[0] == -1)
            return 0;

        vector<vector<Edge> > edges(n[0]+n[1]*2+n[2]*2+n[3]+10);
        for(int i=0; i<n[0]; ++i)
            edges[0].push_back(Edge(2+i, 1));

        int a = 2;
        int b = n[0] + 3;
        for(int i=0; i<3; ++i){
            for(int j=0; j<n[i+1]; ++j){
                int x;
                cin >> x;
                while(--x >= 0){
                    int y;
                    cin >> y;
                    -- y;
                    edges[a+y].push_back(Edge(b+j, 1));
                }
            }

            for(int j=0; j<n[i]; ++j)
                edges[a+j].push_back(Edge(b+n[i+1], 1));
            for(int j=0; j<n[i+1]; ++j)
                edges[a+n[i]].push_back(Edge(b+j, 1));

            if(i < 2){
                a = b;
                b += n[i+1] + 1;

                for(int j=0; j<n[i+1]; ++j)
                    edges[a+j].push_back(Edge(b+j, 1));
                edges[a+n[i+1]].push_back(Edge(b+n[i+1], m[i+1]));

                a += n[i+1] + 1;
                b += n[i+1] + 1;
            }
        }

        for(int i=0; i<n[3]; ++i)
            edges[b+i].push_back(Edge(1, 1));
        edges[b+n[3]].push_back(Edge(1, m[3]));

        cout << maxFlow(edges, 0, 1) << endl;
    }
}