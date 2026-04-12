#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
using namespace std;

int N, M;
vector<int> a, b;
vector<vector<int> > connect;
vector<bool> isVisited;
long long ans;

void dfs(int curr) {
    bool all = true;
    REP (i, N) {
        if (!isVisited[i])
            all = false;
    }
    if (all) {
        ans++;
    }

    for (auto next : connect[curr]) {
        if (isVisited[next])
            continue;
        isVisited[next] = true;
        dfs(next);
        isVisited[next] = false;
    }
}

int main()
{
    cin >> N >> M;
    a.resize(M);
    b.resize(M);
    connect = vector<vector<int> >(N, vector<int>());
    REP (i, M) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        connect[a[i]].push_back(b[i]);
        connect[b[i]].push_back(a[i]);
    }

    isVisited = vector<bool>(N, false);
    isVisited[0] = true;
    dfs(0);
    cout << ans << endl;
}
