#include <iostream>
#include <vector>
using namespace std;

using int64 = long long;

int main() {
    int N;
    cin >> N;

    vector<int64> a(N);
    int64 s = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];

        s += a[i];
    }

    for (int64 K = max(0LL, s - N * (N - 1)); K <= s; K++) {
        bool ok = true;
        int64 sum = 0;
        for (int i = 0; i < N; i++) {
            if ((a[i] + K) % (N + 1) == N) {
                ok = false;
                break;
            }
            sum += (a[i] + K) % (N + 1);
        }
        ok = ok && (sum == s - K);

        if (ok) {
            cout << K << endl;
            break;
        }
    }

    return 0;
}