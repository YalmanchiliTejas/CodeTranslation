#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define mod (ll)(1e9 + 7)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000              //1e9
#define LLINF 2000000000000000000LL //2e18

const int nmax = 8;
bool graph[nmax][nmax] = {false};

int solve(int v, int N, bool visited[nmax])
{
    bool isAll = true;
    REP(i, N)
    {
        if (visited[i] == false)
            isAll = false;
    }
    if (isAll)
        return 1;
    int ret = 0;
    REP(i, N)
    {
        if (graph[v][i] == true && visited[i] == false)
        {
            visited[i] = true;
            ret += solve(i, N, visited);
            visited[i] = false;
        }
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    REP(i, M)
    {
        int s, e;
        cin >> s >> e;
        graph[s - 1][e - 1] = graph[e - 1][s - 1] = true;
    }
    bool visited[nmax] = {false};
    visited[0] = true;
    cout << solve(0, N, visited) << endl;
    return 0;
}