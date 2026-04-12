#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = (a); i < (b); ++i) 

const int MAX_N = 10;
bool graph[MAX_N][MAX_N];
int N, M;
bool vis[MAX_N];

int tansaku(int cur) {
    int cnt = 0;
    bool flg = true;
    REP(i, 0, N) if(!vis[i]) flg = false;
    if(flg) { return 1; }

    REP(i, 0, N) if(graph[cur][i]) {
        if(vis[i]) continue;
        vis[i] = true;
        cnt += tansaku(i);
        vis[i] = false;
    }
    return cnt;
}

void solve(){
    vis[0] = true;
    cout << tansaku(0) << endl;
}

int main()
{
    scanf("%d %d", &N, &M);
    REP(i, 0, M) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        graph[a][b] = graph[b][a] = true;
    }
    solve();
    return 0;
}