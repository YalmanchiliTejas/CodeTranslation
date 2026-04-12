#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> H(n);
    for (int i = 0; i < n; ++i)
        cin >> H[i];

    int count = 1;
    for (int i = 1; i < n; ++i) {
        bool flag = true;
        for (int j = 0; j < i; ++j) {
            if (H[j] > H[i]) {
                flag = false;
                break;
            }
        }

        if (flag)
            ++count;
    }
    cout << count << '\n';
}
