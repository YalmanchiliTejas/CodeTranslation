//#define LOCAL

#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

#define int long long
//typedef long long ll;
#define rep(i,n) for(int i=0; i<n; i++)

using namespace std;

int N, M;
vector<int> G[8];
int a, b;
int ans;
bool visited[8];

void dfs(int v, int n)
{
    if (n == N) {
        ans++;
        return;
    }

    visited[v] = true;

    rep(i,G[v].size()) {
        if (visited[G[v][i]]) continue;
        dfs(G[v][i], n + 1);
    }

    visited[v] = false;
}

signed main()
{
#ifdef LOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    cin >> N >> M;
    rep(i,M) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, 1);

    cout << ans << endl;
}
