#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    auto scores = vector<int>(n);
    for (auto &s_i : scores)
        cin >> s_i;

    auto score_max = 0LL; // when A=n-1, score is 0

    // let c = a - b
    // some k (>=0) exists, a + k*c = n-1
    //   ( k*c < n-1 )
    for (int c = 1; c <= n - 1; c++) {
        auto score = 0LL;
        // when k=0, score is 0.
        for (int k = 1;; k++) {
            int a = (n - 1) - (k * c);
            int b = a - c;
            if (a <= 0 || b <= 0)
                break;

            auto newpos1 = k * c;
            auto newpos2 = (n - 1) - k * c;
            if (newpos2 % c == 0 && newpos2 <= newpos1)
                break;

            score += scores[newpos1] + scores[newpos2];
            score_max = max(score_max, score);
        }
    }

    cout << score_max;
    return 0;
}
