#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, l, r, result;

    vector<int> A;
    bool f;
    while (cin >> n >> l >> r, n) {
        A.resize(n);

        result = 0;

        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = l; i <= r; i++) {
            f = false;
            for (int j = 0; j < n; j++) {
                if (i % A[j] == 0) {
                    if ((j + 1) % 2 == 1) {
                        result++;
                    }
                    f = true;
                    break;
                }
            }
            if (f == false) {
                if (n % 2 == 0) {
                    result++;
                }
            }
        }
        cout << result << endl;
    }
}
