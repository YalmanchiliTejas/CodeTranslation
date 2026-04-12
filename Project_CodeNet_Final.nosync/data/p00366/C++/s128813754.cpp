#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int T[N];
    for (int i = 0; i < N; i++) cin >> T[i];
    sort(T, T + N);

    vector<int> div;
    for (int i = 1; i * i <= T[N - 1]; i++) {
        if (T[N - 1] % i == 0) {
            div.push_back(i);
            div.push_back(T[N - 1] / i);
        }
    }
    sort(div.begin(), div.end());

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        int d = *lower_bound(div.begin(), div.end(), T[i]);
        if (d != T[i]) {
            ans += d - T[i];
        }
    }

    cout << ans << endl;
}
