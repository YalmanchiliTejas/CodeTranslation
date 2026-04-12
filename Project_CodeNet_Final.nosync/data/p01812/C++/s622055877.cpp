#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int darks[16];
int edges[110][110];
int dp[1<<16];
int darksinv[110];

int main() {
    int n,m,k;

    cin >> n >> m >> k;
    for (int i=0; i<m; i++) { cin >> darks[i]; darks[i]--; }
    for (int i=0; i<n; i++) for (int j=0; j<k; j++) { cin >> edges[i][j]; edges[i][j]--; }

    // darks inverse
    for (int i=0; i<n; i++) darksinv[i] = -1;
    for (int i=0; i<m; i++) darksinv[darks[i]] = i;

    for (int i=0; i<(1<<m); i++) dp[i] = -1;
    dp[ (1<<m) - 1] = 0;
    queue<pair<int, int> > q;
    q.push( make_pair( (1<<m) - 1, 0 ) );

    int ans = -1;
    while (!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        int state = p.first;
        int cost  = p.second;

        for (int i=0; i<k; i++) {
            int next_state = 0;
            for (int j=0; j<m; j++) {
                if (!(state & (1<<j))) continue;
                if (darksinv[edges[darks[j]][i]] != -1) {
                    next_state |= (1 << darksinv[edges[darks[j]][i]]);
                }
            }
            if (next_state == 0) {
                ans = cost + 1;
                break;
            }
            if (dp[next_state] == -1) {
                dp[next_state] = cost + 1;
                q.push( make_pair(next_state, cost + 1) );
            }
        }

        if (ans != -1) break;
    }

    cout << ans << endl;

    return 0;
}