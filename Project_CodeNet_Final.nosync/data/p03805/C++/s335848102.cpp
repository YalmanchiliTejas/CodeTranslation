#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> edge(N+1, vector<bool>(N+1, false));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edge[a][b] = true;
        edge[b][a] = true;
    }
    vector<int> list;
    for (int i = 2; i <= N; i++) list.push_back(i);
    int ans = 0;
    while (true) {
        bool check = true;
        for (int i = 0; i < N-1; i++) {
            if (i == 0) {
                if (!edge[1][list[0]]) {
                    check = false;
                    break;
                }
            } else {
                if (!edge[list[i-1]][list[i]]) {
                    check = false;
                    break;
                }
            }
        }
        if (check) ans++;
        if (!next_permutation(list.begin(), list.end())) break;
    }
    cout << ans << endl;
    return 0;
}