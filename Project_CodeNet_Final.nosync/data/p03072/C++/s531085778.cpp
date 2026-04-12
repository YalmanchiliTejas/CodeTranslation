#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int M = 0, cnt = 0;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H.at(i);
        if (H.at(i) == max(M, H.at(i))) {
            cnt++;
            M = max(M, H.at(i));
        }
    }
    cout << cnt << endl;
}