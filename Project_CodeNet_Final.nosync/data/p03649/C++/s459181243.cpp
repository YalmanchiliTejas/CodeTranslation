#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    int64_t n;
    cin >> n;

    vector<int64_t> as(n);

    int64_t sum = 0;
    for (auto& a : as) {
        cin >> a;
        sum += a;
    }

    // int64_t lo = 0, hi = sum;
    // while (hi - lo > 1) {
    //     int64_t mi = (hi + lo) / 2;

    //     int64_t tt = 0;
    //     for (auto& a : as) {
    //         tt += (a + mi) / (n + 1);
    //     }

    //     cout << lo << " - " << hi << ": " << tt << endl;

    //     if (mi >= tt) {
    //         lo = mi;
    //     } else {
    //         hi = mi;
    //     }
    // }

    // cout << lo << endl;

    int64_t v = 0;
    for (;;) {
        sort(as.begin(), as.end());
        if (as[n - 1] < n) {
            break;
        }

        // for (int i = 0; i < n; i++) {
        //     cout << as[i] << " ";
        // }
        // cout << endl;

        if (as[0] >= n) {
            int64_t dec = as[0] - (n - 1);
            for (int i = 0; i < n; i++) {
                as[i] -= dec;
            }
            v += dec * n;
            continue;
        }

        int64_t dec = as[n - 1] / n;
        as[n - 1] %= n;
        v += dec;
        for (int i = 0; i < n - 1; i++) {
            as[i] += dec;
        }
    }
    cout << v << endl;

    return 0;
}
