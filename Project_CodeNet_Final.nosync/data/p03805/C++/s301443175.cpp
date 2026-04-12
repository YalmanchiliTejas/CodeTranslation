#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define OUT(a) cout << (a) << "\n"
#define ll long long
#define uint unsigned int
#define ushort unsigned short
#define ulong unsigned long

ll MOD = 10e9 + 7;
int n,m;

int dfs(vector<vector<int> > rinsetsu, vector<int> dist, int now) {
    if (dist[now] == n) return 1;
    int size = rinsetsu[now].size();
    int res = 0;
    REP(i, size) {
        if (dist[rinsetsu[now][i]] != 0) continue;
        dist[rinsetsu[now][i]] = dist[now] + 1;
        res += dfs(rinsetsu, dist, rinsetsu[now][i]);
        dist[rinsetsu[now][i]] = 0;
    }
    return res;
}

int main() {
    cin >> n >> m;
    auto rinsetsu = vector<vector<int> >(n, vector<int>());
    REP(i, m) {
        int a,b;
        cin >> a >> b;
        rinsetsu[a-1].push_back(b-1);
        rinsetsu[b-1].push_back(a-1);
    }
    vector<int> dist(n, 0);
    dist[0] = 1;
    cout << dfs(rinsetsu, dist, 0) << endl;
    return 0;
}

