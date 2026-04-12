#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector< vector<int> > G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> ord(N);
    for (int i = 0; i < N; i++) ord[i] = i;

    int ans = 0;
    do {
        if (ord[0] != 0) continue;
        bool flag = true;
        for (int i = 0; i < N - 1; i++) {
            auto Iter = find(G[ord[i]].begin(), G[ord[i]].end(), ord[i + 1]);
            if (Iter == G[ord[i]].end()) flag = false;
        }
        if (flag) ans++;
    } while(next_permutation(ord.begin(), ord.end()));

    cout << ans << endl;
}
