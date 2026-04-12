#include <iostream>
using namespace std;

int main() {
    int64_t n, k;
    cin >> n >> k;

    int64_t answer = 0;
    if (k == 0) {
        answer = n * n;
    } else {
        for (int64_t b = k + 1; b <= n; b++) {
            int64_t x = ((n + 1) % b >= k ? k : (n + 1) % b) + (n + 1) / b * k;
            answer += n + 1 - x;
        }
    }
    cout << answer << endl;
    return 0;
}
