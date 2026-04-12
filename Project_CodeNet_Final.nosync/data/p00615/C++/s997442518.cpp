#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if ((n | m) == 0) {
            break;
        }
        int* passTimes = new int [n + m + 1];
        for (int i = 1; i <= n; i++) {
            cin >> passTimes[i];
        }
        for (int i = n + 1; i <= n + m; i++) {
            cin >> passTimes[i];
        }
        passTimes[0] = 0;
        for (int i = 1; i < n + m; i++) {
            for (int j = 1; j < n + m - i; j++) {
                if (passTimes[j] > passTimes[j + 1]) {
                    int temp = passTimes[j];
                    passTimes[j] = passTimes[j + 1];
                    passTimes[j + 1] = temp;
                }
            }
        }
        int maxGap = 0;
        for (int i = 0; i < n + m; i++) {
            int gap = passTimes[i + 1] - passTimes[i];
            if (maxGap < gap) {
                maxGap = gap;
            }
        }
        cout << maxGap << endl;
        delete[] passTimes;
    }
}