#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const int mod = 1000000007;

vector<vector<int>> graph(8,vector<int>(8,0));
int N, M;
int cnt = 0;
vector<int> seen(8,0);

void dfs(int now, int depth){


    // 探索する頂点が探索済ならreturn
    if(seen[now] == 1){
        return;
    }

    // 全部の頂点を探索済ならcntをインクリメントする
    if(depth == N){
        cnt += 1;
        return;
    }

    seen[now] = 1;
    for(int i = 0; i < N; i++){
        if(graph[now][i] == 1) {
            int next = i;
            dfs(next, depth + 1);
        }
    }
    seen[now] = 0;
    return;
}

int main(){
    cin >> N >> M;
    vector<int> a(M), b(M);
    rep(i, M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    rep(i, M){
        graph[a[i]][b[i]] = 1;
        graph[b[i]][a[i]] = 1;
    }

    dfs(0, 1);
    cout << cnt << endl;
    return 0;
}
