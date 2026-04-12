#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
typedef long long int ll;
using namespace std;
using Graph = vector<vector<int> >;
Graph G;
bool seen[10]={false};
int N;
int res=0;

void dfs(int v) {
    bool end = true;
    rep(i,N){
        if (!seen[i] && i != v) end = false;
    }
    if (end) {
        ++res;
        return;
    }

    seen[v] = true;
    for (auto nv : G[v]) {
        if (seen[nv]) continue;
        dfs(nv);
    }
    seen[v] = false;
}

int main() {
    int M;
    cin >> N >> M;
    G.assign(N, vector<int>());

    rep(i,M){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0);
    cout << res << endl;

 //   system("pause");
    return 0;
}