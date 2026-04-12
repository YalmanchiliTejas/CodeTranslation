#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define FORr(i, j, k) for(int i = j; i >= k; --i)
#define repr(i, j) FORr(i, j, 0)
#define INF (1<<30)
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> Pi;

int N, M;
vector<int> G[10];
bool went[10];
int cnt = 0;

void dfs(int V) {
        FOR(i, 1, N + 1) {
                if(!went[i]) break;
                if(i == N) {
                        ++cnt;
                        return;
                }
        }
        rep(i, G[V].size()) {
                if(!went[G[V][i]]) {
                        went[G[V][i]] = true;
                        dfs(G[V][i]);
                        went[G[V][i]] = false;
                }
        }
        return;
}

int main() {
        scanf("%d %d", &N, &M);
        memset(went, false, sizeof(went));
        rep(i, M) {
                int a, b;
                scanf("%d %d", &a, &b);
                G[a].push_back(b);
                G[b].push_back(a);
        }
        went[1] = true;
        dfs(1);
        printf("%d\n", cnt);
        return 0;
}