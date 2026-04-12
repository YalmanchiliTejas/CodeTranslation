#include <iostream>

using namespace std;

int main() {

    int n;
    while (cin >> n) {
        if (n == 0) break;

        int sum = 0, min_ = 1001, max_ = -1;
        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;
            sum += s;
            min_ = min(min_, s);
            max_ = max(max_, s);
        }

        cout << (sum - min_ - max_) / (n - 2) << endl;
    }
}

