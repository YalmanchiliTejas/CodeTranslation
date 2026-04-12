#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, ans = 0, arr[10], a, b;
    vector<int> v[10];
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < N; ++i) arr[i] = i;

    do {
        if (arr[0]) break;
        bool can = true;
        for (int i = 0; i < N - 1; ++i) {
            bool can2 = false;
            for (int j = 0; j < v[arr[i]].size(); ++j) {
                if (v[arr[i]][j] == arr[i + 1]) {
                    can2 = true;
                    break;
                }
            }
            if (!can2) {
                can = false;
                break;
            }
        }
        if (can) ++ans;
    } while (next_permutation(arr, arr + N));

    cout << ans << endl;

    return 0;
}