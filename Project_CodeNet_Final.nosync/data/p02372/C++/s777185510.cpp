#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;
long long int INF = 1e18;

struct edge{
    int to;
    long long int cost;
};

#define MAX_V 110000
vector<edge> E[MAX_V];
long long int d1[MAX_V], d2[MAX_V];
 
void func(int u, int pre, int dist, long long int d[]){
    d[u] = dist;
    for(int i = 0; i < E[u].size(); i++){
        if(E[u][i].to != pre){
            func(E[u][i].to, u, dist + E[u][i].cost, d);
        }
    }
}

int main(){
     
    int N;
    cin >> N;
     
    for(int i = 0; i < N - 1; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edge p;
        p.cost = c;
        p.to = v;
        E[u].push_back(p);
        p.to = u;
        E[v].push_back(p);
    }
     
    func(0, -1, 0, d1);
     
    int index = 0;
    int dmax = 0;
    for(int i = 0; i < N; i++){
        if(d1[i] > dmax){
            dmax = d1[i];
            index = i;
        }
    }
    func(index, -1, 0, d1);
     
    dmax = 0;
    for(int i = 0; i < N; i++){
        if(d1[i] > dmax){
            dmax = d1[i];
            index = i;
        }
    }
    func(index, -1, 0, d2);
	
    for(int i = 0; i < N; i++){
    	cout << max(d1[i], d2[i]) << endl;
    }
     
    return 0;
}
