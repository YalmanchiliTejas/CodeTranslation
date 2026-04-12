#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n, t, e;
    while (cin >> n >> t >> e) {
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        int result = -1;
        for (int i = 0; i < n; i++) {
            for (int xx = x[i]; xx <= t + e; xx += x[i]) {
                if (xx >= t - e) {
                    result = i + 1;
                }
            }
            if (result > 0) {
                break;
            }
        }
        cout << result << endl;
    }
}