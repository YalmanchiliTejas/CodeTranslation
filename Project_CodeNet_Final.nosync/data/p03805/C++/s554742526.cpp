#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

vector<vector<int>> g;
int ans = 0;

void dfs(vector<bool> visit, int par,int cnt) {
    visit[cnt] = true;
    if (find(ALL(visit),false) == visit.end()) {
        ans++;
        return;
    }
    for(auto x:g[cnt] ) {
        if (x == par) continue;
        if (visit[x]) continue;
        dfs(visit,cnt,x);
    }
}

int main(void)
{
    IOS
    int N, M;
    cin >> N >> M;
    g.resize(N);
    REP(i,M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(vector<bool>(N),-1,0);

    cout << ans << '\n';


    return 0;
}