#include <bits/stdc++.h>
using namespace std;

#define in cin
#define out cout

#define REP(i,n) for(int i=0; i<n; i++)
#define REP2(i,s,e) for(int i=s; i<e; i++)
#define REPE(i,s,e) for(int i=s; i<=e; i++)
#define REPR(i,s,e) for(int i=s; i>=e; i--)

#define all(v) v.begin(), v.end()
#define pb push_back

#define ll long long
#define pii pair<int, int>

#define x first
#define y second
#define intINF 2147483647
#define llINF 9223372036854775807LL
#define MOD 1000000007

int n, m;
string M[10];

int dfs(int x, int y)
{
    M[x][y] = '.';
    if(x != n-1 && M[x+1][y] == '#') dfs(x+1, y);
    else if(y != m-1 && M[x][y+1] == '#') dfs(x, y+1);
}

int main()
{
    in >> n >> m;
    REP(i, n) in >> M[i];

    dfs(0, 0);

    bool flag = true;
    REP(i, n) REP(j, m) if(M[i][j] == '#') flag = false;

    out << (flag ? "Possible" : "Impossible") << "\n";

    return 0;
}
