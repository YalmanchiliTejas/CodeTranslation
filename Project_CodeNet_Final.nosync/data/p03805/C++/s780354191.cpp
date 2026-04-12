#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M, ans = 0;
    cin >> N >> M;
    vector<vector<bool>> reachable(N, vector<bool>(N));
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        reachable[a][b] = reachable[b][a] = true;
    }
    vector<int> route(N);
    for(int i = 0; i < N; ++i)
        route[i] = i;
    do {
        int ok = true;
        for(int i = 1; i < N; ++i) {
            if(!reachable[route[i - 1]][route[i]]) {
                ok = false;
                break;
            }
        }
        if(ok)
            ++ans;
    } while(next_permutation(route.begin() + 1, route.end()));
    cout << ans << endl;
    return 0;
}
