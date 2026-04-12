#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    int cnt = 1;
    int maxv = H[0];
    for (int i = 1; i < N; i++) {
        if (maxv <= H[i]) cnt++;
        maxv = max(maxv, H[i]);
    }
    cout << cnt << endl;
}