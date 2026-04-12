

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
int G[10][10], dp[1<<10][10];

int main(void) {
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a][b] = G[b][a] = true;
    }
    dp[1][0] = 1;
    for (int S=1; S<(1<<N)-1; S++) {
        for (int u=0; u<N; u++) for (int v=0; v<N; v++) {
            if (!((S>>v)&1) && G[u][v]) dp[S|(1<<v)][v] += dp[S][u];
        }
    }

    for (int i=0; i<N; i++) ans += dp[(1<<N)-1][i];
    
   

    printf("%d\n", ans);

	return 0;
}
