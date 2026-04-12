#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int cnt = 0;
    int maxv = 0;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        if (maxv <= h) {
            maxv = h;
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
