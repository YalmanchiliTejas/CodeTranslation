#include <iostream>
using namespace std;
int main() {
    int N, H[20];
    cin >> N >> H[0];
    int cnt = 1, highest = H[0];
    for (int i = 1; i < N; i++) {
        cin >> H[i];
        if (H[i] >= highest) {
            cnt++;
            highest = H[i];
        }
    }
    cout << cnt << endl;
}