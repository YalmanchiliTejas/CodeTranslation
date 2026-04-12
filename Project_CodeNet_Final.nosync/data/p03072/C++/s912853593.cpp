#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int max_H = H[0];
    int ans = 1;
    for(int i = 1; i < N; i++) {
        if(H[i] >= max_H) {
            ans++;
            max_H = H[i];
        }
    }   

    cout << ans << endl;

    return 0;
}