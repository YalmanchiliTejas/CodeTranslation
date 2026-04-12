#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

struct UnionFind{
    vector<int> data;
	UnionFind(int size):data(vector<int>(size,-1)){}
    bool unionSet(int x,int y){
        x = root(x),y = root(y);
        if(x != y){
			if(data[y] < data[x])swap(x,y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x,int y){return root(x) == root(y);}
    int root(int x){return data[x] < 0 ? x : data[x] = root(data[x]);}
    int size(int x){return -data[root(x)];}
};

int main(){
    int N;
    cin >> N;
    vector<pair<int, int> > X(N);
    vector<pair<int, int> > Y(N);
    REP(i, N){
        int x, y;
        cin >> x >> y;
        X[i] = make_pair(x, i);
        Y[i] = make_pair(y, i);
    }
    sort(ALL(X));
    sort(ALL(Y));
    vector<pair<LL, pair<int, int> > > edges;
    REP(i, N-1){
        LL dx = X[i+1].first - X[i].first;
        LL dy = Y[i+1].first - Y[i].first;
        edges.push_back(make_pair(dx, make_pair(X[i+1].second, X[i].second)));
        edges.push_back(make_pair(dy, make_pair(Y[i+1].second, Y[i].second)));
    }
    sort(ALL(edges));
    UnionFind uf(N);
    LL res = 0;
    REP(i, edges.size()){
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(uf.unionSet(a, b)){
            res += edges[i].first;
        }
    }
    cout << res << endl;

    return 0;
}
