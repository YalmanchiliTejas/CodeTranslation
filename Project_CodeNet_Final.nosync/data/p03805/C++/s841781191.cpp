#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
//typedef pair<int,int> P;
typedef pair<ll, ll> P;
//typedef pair<int, pair<int, pair<int, int>>> P;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
int INFM =100000000;
ll MOD  = 1000000007;

const int nmax = 8;
bool gragh[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){
    
    bool all_visited = true;
    
    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            all_visited = false;
        }
    }
    
    if(all_visited){
        return 1;
    }
    
    int ret = 0;
    
    for(int i = 0; i < N; i++){
        if(gragh[v][i] == false) continue;
        if(visited[i]) continue;
        
        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }
    return ret;
    
}


int main(){
    int N,M;
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int A,B;
        cin >> A >> B;
        gragh[A-1][B-1] = gragh[B-1][A-1] = true;
    }
    
    bool visited[nmax];
    for(int i = 0; i < N; i++){
        visited[i] = false;
    }
    
    visited[0] = true;
    cout << dfs(0, N, visited) << endl;
}