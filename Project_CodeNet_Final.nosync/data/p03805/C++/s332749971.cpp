

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int ans;
int N, M;
vector<int> g[10]; 
bool used[10];

void dfs(int u) {
    bool ok = true;
    for (int i=1; i<=N; i++) {
        if (!used[i]) ok = false;
    }
    if(ok) {
        ans++;
        return;
    }

    for(int i=0; i<(int)g[u].size(); i++) {
        int v = g[u][i];
        if (!used[v]) {
            used[v] = true;
            dfs(v);
            used[v] = false;
        }
    }
} 

int main(void) {
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    used[1] = true;
    dfs(1);
   

    printf("%d\n", ans);

	return 0;
}
