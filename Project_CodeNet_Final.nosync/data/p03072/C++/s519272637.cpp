#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<int> H(N);

    rep(i, N)
        cin >> H.at(i);
    
    int ans = 0;
    int minv = 0;
    rep(i, N) {
        if (H.at(i) >= minv) {
            ans++;
            minv = H.at(i);
        }
    }

    cout << ans << endl;
}