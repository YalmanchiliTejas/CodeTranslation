#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n,m;
bool G[8][8];
int ans = 0;
bool reached[8];

void DFS(int v, int cnt){
    if(cnt == n){
        ans++;
        return;
    }
    reached[v] = true;
    REP(i,n){
        if(reached[i] == false && G[v][i] == true) DFS(i,cnt + 1);
    }
    reached[v] = false;
    return;
}

signed main(){
    cin >> n >> m;
    int a,b;
    REP(i,m){
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = true;
        G[b][a] = true;
    }
    DFS(0,1);
    cout << ans << endl;
}