#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

class Edge
{
public:
    int to, cost;
    Edge(){};
    Edge(int to0, int cost0){to = to0; cost = cost0;}
};

long long minSpanningTree(const vector<vector<Edge> >& edges)
{
    int n = edges.size();
    vector<bool> used(n, false);
    int usedNum = 0;
    vector<int> minCost(n, INT_MAX);
    priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push(make_pair(0, 0));

    long long ret = 0;
    while(!q.empty()){
        pair<int, int> p = q.top();
        q.pop();
        int v = p.second;
        if(used[v])
            continue;
        ret += p.first;
        used[v] = true;
        if(++usedNum == n)
            return ret;
        for(unsigned i=0; i<edges[v].size(); ++i){
            Edge e = edges[v][i];
            if(!used[e.to] && e.cost < minCost[e.to]){
                minCost[e.to] = e.cost;
                q.push(make_pair(e.cost, e.to));
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int> > > v(2, vector<pair<int, int> >(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<2; ++j){
            cin >> v[j][i].first;
            v[j][i].second = i;
        }
    }

    vector<vector<Edge> > edges(n);
    for(int i=0; i<2; ++i){
        sort(v[i].begin(), v[i].end());
        for(int j=0; j<n-1; ++j){
            int a = v[i][j].second;
            int b = v[i][j+1].second;
            int c = v[i][j+1].first - v[i][j].first;
            edges[a].push_back(Edge(b, c));
            edges[b].push_back(Edge(a, c));
        }
    }
    cout << minSpanningTree(edges) << endl;

    return 0;
}
