#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i,a,b) for(int i=int(a);i<int(b);i++)

using namespace std;

typedef long long int lli;

int main () {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(N, 0));
    REP (i, 0, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    vector<int> nlist(N);
    REP (i, 0, N) nlist[i] = i;
    int ans = 0;
    do {
        bool run = true;
        REP (i, 0, N - 1) {
            int first = nlist[i];
            int second = nlist[i + 1];
            if (G[first][second] == 0) run = false;
        }
        ans += run;
    } while(next_permutation(nlist.begin() + 1, nlist.end()));
    cout << ans << endl;
    return 0;
}
