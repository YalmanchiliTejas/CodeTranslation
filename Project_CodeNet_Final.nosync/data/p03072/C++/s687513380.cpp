#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> H(N);
    for (int i; i < N; ++i) cin >> H[i];

    int mx = 0, cnt = 0;
    for (int i=0; i<N; ++i) {
        if (mx <= H[i]) {
            cnt ++;
            mx = max(mx, H[i]);
        }
    }

    cout << cnt << endl;

    return 0;
}