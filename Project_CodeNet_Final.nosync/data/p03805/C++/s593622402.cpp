#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

vector<vector<int>> v;
int ans=0;

void dfs(vector<bool> &visit,int cnt) {
    visit[cnt] = true;
    bool all = true;
    REP(i,visit.size()) {
        if (!visit[i]) {
            all = false;
            break;
        }
    }
    if (all) {
        ans++;
        return;
    }
    for(auto x: v[cnt]) {
        if (!visit[x]) {
            vector<bool> vi(visit);
            dfs(vi,x);
        }
    }
    return;
}

int main(void)
{
    IOS
    int n, m;
    cin >> n >> m;
    v.resize(n);
    REP(i,m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    vector<bool> vi(n);
    dfs(vi,0);

    cout << ans << endl;

    return 0;
}