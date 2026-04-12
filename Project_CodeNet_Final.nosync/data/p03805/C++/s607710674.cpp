#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> rel;
vector<int> visited;
int ans = 0;


bool check(){
    for(int &i:visited)
        if(!i) return false;
    return true;
}

void solve(int s){
    visited[s] = 1;
    for(int i=0; i<N; i++){
        if(rel[s][i] == 1 && !visited[i]){
            solve(i);
        }
    }
    if(check()) ans++;
    visited[s] = 0;
}

int main() {
    cin >> N >> M;
    visited.resize(N);
    rel.resize(N);
    for(vector<int> &v:rel)
        v.resize(N);
    
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        rel[a][b] = rel[b][a] = 1;
    }
    solve(0);
    cout << ans << endl;
    return 0;
}
