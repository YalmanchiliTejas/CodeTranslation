#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int nmax=8;
bool graph[nmax][nmax];
bool used[nmax];
int N,M;
int ans;

#define rep(i, n) for(int i = 0; i < (n); i++)
void dfs(int v, int cnt){
    if(cnt == N){
      ans ++;
      return;
    }
    used[v] = true;
    rep(i, N){
        if((!used[i]) && graph[i][v]){
            dfs(i, cnt + 1);
        }
    }
    used[v] = false;
}


int main() {
    cin >> N >> M;
    rep(i, M){
        int s,e;
        cin >> s >> e;
        s --;
        e --;
        graph[s][e] = graph[e][s] = true;
    }
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}