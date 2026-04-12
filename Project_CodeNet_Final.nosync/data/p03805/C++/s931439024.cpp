#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N,vector<int>(N,0));
    REP(i,M){ 
        int a,b; cin >> a >> b; a--;b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }

    vector<int> way(N);
    REP(i,N) way[i] = i;

    int ans = 0;
    do{
        if(way[0] == 0){
            bool ok = true;
            REP(i,N-1){
                if(G[way[i]][way[i+1]]==0) ok = false;
            }
            if(ok) ans ++;
        }
    }while(next_permutation(ALL(way)));
    cout << ans << endl;
    return 0;
}