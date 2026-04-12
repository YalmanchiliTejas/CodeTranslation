#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int> > gragh(N);
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        gragh.at(a - 1).push_back(b);
        gragh.at(b - 1).push_back(a);
    }

    vector<int> path(N - 1);
    bool can1, can2;
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        path.at(i) = i + 2;
    }
    do {
        can1 = true;
        for (int i = 0; i < N - 1; i++) {
            can2 = false;
            int j;
            if (i == 0) {
                j = 1;
            }
            else {
                j = path.at(i - 1);
            }
            for (int k = 0; k < gragh.at(j - 1).size(); k++) {
                if (gragh.at(j - 1).at(k) == path.at(i)) {
                    can2 = true;
                }
            }
            if (!can2) {
                can1 = false;
            }
        }
        if (can1) {
            ans++;
        }
    } while (next_permutation(path.begin(), path.end()));

    cout << ans << endl;
}