#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)

using namespace std;
typedef long long ll;

using Graph = vector<vector<int>>;
typedef pair<int, int> P;

int N,M;

bool check(Graph G, vector<int> v){
    rep(i,N-1){
        if(!G[v[i]][v[i+1]]){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> N >> M;
    Graph G(N,(vector<int>(N,0)));
    rep(i,M) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a][b] = G[b][a] = 1;
    }
    vector<int> v(N);
    rep(i,N) v[i] = i;
    long long ans = 0;
    do{
        if(v[0]==0 && check(G, v)) ans++;
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}

