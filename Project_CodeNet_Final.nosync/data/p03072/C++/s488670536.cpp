#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h[n], l[n];
    for (int i=0; i<n; i++) cin >> h[i];

    int sum = 0;
    for (int i=0; i<n; i++) {
        int sw = 1;
        for (int j=0; j<i; j++) {
            if (h[j] > h[i]) {
                sw = 0;
                break;
            }
        }
        if (sw) sum++;
    }
    cout << sum << endl;

    return 0;
}
