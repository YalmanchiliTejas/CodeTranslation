#include <iostream>
using namespace std;

int main() {
    int n, H[20];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> H[i];
    }

    int high  = 0;
    int count = 1;

    high = H[0];
    for (int j = 1; j < n; j++) {
        if (H[j] > high) {
            high = H[j];
        }
        if (H[j] >= high) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
