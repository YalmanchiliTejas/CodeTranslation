#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > Graph;
#define rep(i, n) for(int i=0; i<n; i++) 

int main() {
    int N, M;
    cin >> N >> M;
    
    Graph G(N, vector<int>(N, 0));
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        
        G[u][v] = 1;
        G[v][u] = 1;
    }
    
    int array[N-1];
    rep(i, N-1) {
        array[i] = i+1;
    }

    int ans=0;
    
    do {
        int st = 0;
        bool flag;
        
        rep(i, N-1) {
            flag=false;
            if(G[st][array[i]]) flag=true;
            if(!flag) break;
            st = array[i];
        }
        
        if(flag) ans++;
        
    } while(next_permutation(array, array+N-1));

    cout << ans << endl;

    return 0;
    
}