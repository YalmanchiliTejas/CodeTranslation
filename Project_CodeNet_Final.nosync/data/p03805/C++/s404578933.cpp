#include <bits/stdc++.h>

#define PI 3.1415926535897932
#define MOD 1000000007
#define INF 1e9

#define REP(i, n) for(int i = 0; i < (n); i++)
#define REP1(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, start, end) for(int i = (start); i < (end); i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;


int N, M;
vvi G;
vb visited;

int dfs(int s)
{
    int path = 0;
    visited[s] = true;
    bool isReef = true;
    REP(i, N)
    {
        if(G[s][i] == 1 && !visited[i])
        {
            isReef = false;
            path += dfs(i);
        }
    }
    bool allVisited = true;
    REP(i, N) if(visited[i] == false) allVisited = false;
    visited[s] = false;
    if(isReef && !allVisited) return 0;
    else if(isReef) return 1;
    return path;
}

void solve()
{
    cin >> N >> M;
    G = vvi(N, vi(N, 0)); 
    visited = vb(N, false);
    REP(i, M)
    {
        int a, b; cin >> a >> b;
        G[--a][--b] = 1;
        G[b][a] = 1;
    }
    cout << dfs(0) << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();

    return 0;
}