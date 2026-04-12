#include <bits/stdc++.h>
using namespace std;
int main() {
    #ifdef DEBUG
    std::ifstream in("/home/share/inputf.in");
    std::cin.rdbuf(in.rdbuf());
    #endif
    int N;
    cin >> N;
    vector<int64_t> s(N);
    for(int i = 0; i < N; i++) {
        cin >> s[i];
    }
    int64_t ans = 0;
    for(int C = 1; C < N; C++) {
        int64_t score = 0;
        for(int k = 0; (k + 1) * C < N; k++) {
            score += s[k * C] + s[N - 1 - k * C];
            if ((N - 1) % C != 0 || N - 1 > 2 * k * C) {
                ans = max(ans, score);
            }
        }
    }
    cout << ans << endl;
    return 0;
}