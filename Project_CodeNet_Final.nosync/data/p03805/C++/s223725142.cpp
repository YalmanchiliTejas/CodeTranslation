#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> AB(M);
    for (int i = 0; i < M; i++) cin >> AB[i].first >> AB[i].second;

    int ans = 1;
    for (int i = 1; i < N; i++) ans *= i;
    vector<int> array(N - 1);
    for (int i = 0; i < N - 1; i++) array[i] = i + 2;
    do {
        vector<int> solve = {1};
        for (int i = 0; i < N - 1; i++) solve.push_back(array[i]);
        for (int i = 1; i < N; i++) {
            bool flag = false;
            for (int j = 0; j < M; j++) {
                if (make_pair(solve[i - 1], solve[i]) == AB[j] || make_pair(solve[i], solve[i - 1]) == AB[j]) {
                    flag = true;
                }
            }
            if (!flag) {
                ans--;
                break;
            }
        }
    } while (next_permutation(array.begin(), array.end()));

    cout << ans << endl;
}