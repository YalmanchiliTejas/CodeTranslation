#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int ans = 0;
int N, M;
vector<vector<int> > V;
int walk(int x, bool visited[]){
    /* 閉路対策 */
    bool flag = true;
    for(int i = 0; i < N; i++) if(visited[i] == false) flag = false;
    
    if(flag) return 1;
    
    int ret = 0;
    for(int  i = 0; i < V[x].size(); i++){
        if(!visited[V[x][i]]) {
            visited[V[x][i]] = true;
            ret += walk(V[x][i], visited);
            visited[V[x][i]] = false;
        }
    }
    return ret;
}

int main(void){
    // Your code here!
    cin >> N >> M;
    V.resize(N);
    int a;
    int b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        a--;
        b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    bool visited[N];
    for(int i=0; i < N; i++) visited[i] = false;
    visited[0] = true;
    cout << walk(0, visited) << endl;
}
