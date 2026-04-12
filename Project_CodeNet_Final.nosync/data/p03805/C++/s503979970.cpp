#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }

typedef long long ll;

void dfs(const int &N,int &count,const  int &visiting,vector<int> visited,const vector<vector<int>> &G) {
    visited.push_back(visiting);
    if (visited.size()==N) {
        count++;
        return;
    }
    auto roots = G[visiting];
    vector<int> avails;
    for(const auto& root:roots) {
        auto it = find(ALL(visited),root);
        // iteratorのendは(最終要素の「次」)
        if (it != visited.end()) continue;
        else avails.push_back(root);
    }
    for(const auto& el:avails) {
        dfs(N,count,el,visited,G);
    }

}


int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>> G(N+1);
    REP(i,M) {
        int a,b;
        cin >> a >> b;
        G[b].push_back(a);
        G[a].push_back(b);
    }
    int ans=0;
    vector<int> dmy;
    dfs(N,ans,1,dmy,G);
    cout << ans << endl;



    return 0;
}
