#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

vector<int> G[9];
int visited[9];
int N, M;
int dfs(int u = 0, int cnt = 1) {
    visited[u] = true;
    int ret = (cnt == N);
    for(auto to: G[u]) {
        if(visited[to]) continue;
        ret += dfs(to, cnt + 1);
    }
    visited[u] = false;
    return ret;
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << dfs() << endl;

    return 0;
}
