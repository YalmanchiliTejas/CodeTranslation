#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool check(vector<ll> path, vector<vector<ll>> &graph){
    if(path[0] != 0)return false;

    bool flag = true;
    for( int i = 0; i < (int)path.size() - 1; i++ ){
        if( graph[ path[i+1] ][ path[i] ] == 0 ) flag = false;
    }

    return flag;
}

int main() {
    ll ans = 0LL, N, M; cin >> N >> M;
    vector<vector<ll>> graph(N,vector<ll>(N,0));

    for( int i = 0; i < M; i++ ){
        ll a, b; cin >> a >> b; a--; b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    vector<ll> path(N);
    for( int i = 0; i < N; i++ ){
        path[i] = i;
    }

    do{
        if( check(path,graph) ) ans++;
    }while(  next_permutation( path.begin(), path.end() )  );

    cout << ans << endl;
}