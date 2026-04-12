#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    int ans = 0;
    int m = H[0];
    for (int i = 1; i <= N; i++) {
        if (m <= H[i]) {
            ans++;
        }
        m = max(m, H[i]); 
    }
    cout << ans << endl;
    return 0;
}