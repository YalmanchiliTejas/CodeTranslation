#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define INF 1000000000 //1e9

int graph[8][8];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    vector<int> v(N);
    for(int i=0;i<N;i++) v[i] = i;
    int ans = 0;
    do {
        if (v[0] != 0) continue;
        bool ok = true;
        for(int i=0;i<N-1;i++) {
            if (!graph[v[i]][v[i+1]]) ok = false;
        }
        if (ok) ans++;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}