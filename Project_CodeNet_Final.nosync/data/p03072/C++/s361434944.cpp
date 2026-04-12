#include <bits/stdc++.h>
using namespace std;

int N;
int H[20];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    int ans = 0;
    int maxh = 0;
    for (int i = 0; i < N; ++i) {
        if (maxh <= H[i]) {
            ++ans;
            maxh = H[i];
        }
    }
    cout << ans << endl;
    return 0;
}