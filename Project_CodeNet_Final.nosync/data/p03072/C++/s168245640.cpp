#include <iostream>
using namespace std;

int N;
int H[101];
int Max[101];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> H[i];

    Max[0] = H[0];
    for (int i = 1; i < N; i++) {
        Max[i] = Max[i-1];
        if (Max[i-1] < H[i]) Max[i] = H[i];
    }

    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (Max[i] <= H[i]) ans++;
    }

    cout << ans << endl;
}