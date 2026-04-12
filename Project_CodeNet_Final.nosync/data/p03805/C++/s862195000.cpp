#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;

int N,M;
int ans = 0;

void dfs(Graph &G, set<int> &S, int i) {
    
    if (S.size()==N) {
        ans++;
        return;
    }

    else {
        for(auto j: G[i]){
            if (!S.count(j)) {
                S.insert(j);
                dfs(G,S,j);
                S.erase(j);
            }            
        }

    }

}

int main (){
    
    cin >> N >> M;
    Graph G(N);

    int a,b;
    rep(i,0,M) {
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    set<int> S;
    S.insert(0);
    dfs(G,S,0);
    cout << ans << endl;
}


