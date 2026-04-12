#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int N, M;  cin >> N >> M;
    vector<vector<int>> tree(N);
    for(int i=0; i<M; i++){
        int u, v;  cin >> u >> v;
        u--;  v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> path(N);
    for(int i=0; i<N; i++)
        path[i] = i;

    int ans = 0;
    do {
        for(int i=0; i<N-1; i++){
            int u = path[i];
            int v = path[i+1];
            bool ok = false;
            for(int r : tree[u]){
                if(r == v)
                    ok = true;
            }
            if(!ok)
                break;
            
            if(i == N-2){
                ans++;
            }
        }
    } while(next_permutation(path.begin() + 1, path.end()));

    cout << ans << endl;
}
