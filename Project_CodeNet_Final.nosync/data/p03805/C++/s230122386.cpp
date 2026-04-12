#include<iostream>
#include<cstdio>

#include<vector>
#include<string>

#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const ll INF = 1e12+1;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

int N,M;
int G[8][8];
int visited[8];

void dfs_(int u, int &cnt) {
    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) flag = false;
    }
    if (flag) cnt++;
    for (int i = 0; i < N; i++) {
        if (G[u][i] && !visited[i]) {
            visited[i] = true;
            dfs_(i,cnt);
            visited[i] = false;
        }
    }
    
}

int dfs() {
    int cnt = 0;
    visited[0] = true;
    dfs_(0,cnt);
    return cnt;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a][b] = 1;G[b][a] = 1;
    }
    int res = dfs();
    cout << res << endl;
}
