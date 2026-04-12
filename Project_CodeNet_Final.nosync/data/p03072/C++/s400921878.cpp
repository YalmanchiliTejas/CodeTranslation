#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> H(N, 0);
    for (int i = 0; i < N; ++i) cin >> H[i];
    int cnt = 1;
    for (int i = 1; i < N; ++i) {
        bool T = true;
        for (int j = 0; j < i; ++j) {
            if (H[j] > H[i]) {
                T = false; break;
            }
        }
        if (T) cnt++;
    }
    printf("%d\n", cnt);
}
