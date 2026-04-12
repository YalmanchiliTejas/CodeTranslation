#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <deque>
#include <stdio.h>
using namespace std;
 
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
typedef long long ll;
 
template<class T> struct Prim {
 
    struct Edge {
        int to; T cost;
        Edge (int t, T c) : to(t), cost(c) {}
        bool operator < (const Edge &a) const {
            return cost > a.cost;
        }
    };
 
    int N;
    int root;
    vector< vector< Edge > > G;
    vector< vector< Edge > > MST;
    vector< bool > used;
 
    Prim (int n) : G(n), MST(n), used(n), N(n), root(-1) {}
 
    void add_edge(int a, int b, T cost) {
        G[a].push_back(Edge(b,cost));
        G[b].push_back(Edge(a,cost));
        root = a;
    }
 
    void init() {
        priority_queue< pair< Edge, int > > que;
        for (int i = 0; i < G[root].size(); i++) {
            que.push(make_pair(G[root][i],root));
        }
        for (int i = 0; i < N; i++) {
            used[i] = false;
            MST[i].clear();
        }
        used[root] = true;
        while (que.size() != 0) {
            Edge e = que.top().first;
            int from = que.top().second;
            que.pop();
            if (used[e.to]) continue;
            used[e.to] = true;
            MST[e.to].push_back(Edge(from,e.cost));
            MST[from].push_back(e);
            for (int i = 0; i < G[e.to].size(); i++) {
                que.push(make_pair(G[e.to][i],e.to));
            }
        }
    }
 
    T get_cost(void) {
        T ret = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < MST[i].size(); j++) {
                ret += MST[i][j].cost;
            }
        }
        return ret / 2;
    }
 
    vector< Edge > & operator [] (int n) {
        return MST[n];
    }
 
    int size(void) {
        return N;
    }
 
};
 
map< pair<ll,ll>, int> trans;
 
int main () {
 
    int N; cin >> N;
 
    Prim<ll> inst(100010);
 
    vector< pair<ll,ll> > xy(N);
 
    REP(i,N) cin >> xy[i].first >> xy[i].second;
    sort(xy.begin(),xy.end());
    REP(i,N) {
        trans[xy[i]] = i + 1;
    }
 
    REP(i,N - 1) {
        ll cost = min(abs(xy[i].first-xy[i+1].first),abs(xy[i].second-xy[i+1].second));
        inst.add_edge(trans[xy[i]],trans[xy[i+1]],cost);
    }
 
    vector< pair<ll,ll> > ct(N);
    REP(i,N) ct[i] = make_pair(xy[i].second,xy[i].first);
 
    sort(ct.begin(),ct.end());
 
    REP(i,N - 1) {
        ll cost = min(abs(ct[i].first-ct[i+1].first),abs(ct[i].second-ct[i+1].second));
        pair<ll,ll> a = make_pair(ct[i].second,ct[i].first);
        pair<ll,ll> b = make_pair(ct[i+1].second,ct[i+1].first);
        inst.add_edge(trans[a],trans[b],cost);
    }
 
    int v = trans.begin() -> second;
 
    inst.init();
 
    cout << inst.get_cost() << endl;
 
    return 0;
}