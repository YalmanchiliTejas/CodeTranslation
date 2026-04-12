#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    int N, T, E, x, t;
    int ans_idx = 0, ans = INT_MAX;

    cin >> N >> T >> E;

    for (int i = 0; i < N; ++i) {
        cin >> x;

        t = min(abs(T - (T / x) * x), abs(T - ((T + x) / x) * x));
 
        if (t <= E && t < ans) {
            ans = t;
            ans_idx = i + 1;
        }
    }

    if (ans == INT_MAX) {
        cout << "-1\n";
    }
    else
        cout << ans_idx << endl;

    return 0;
}