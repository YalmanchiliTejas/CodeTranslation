#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    string N; cin >> N;
    int K; cin >> K;
    Int ans = 0;
    if (K == 1) {
        for (int i = 0; i < N.size(); i++) {
            if (i == 0) ans += N[i] - '0';
            else ans += 9;
        }
    } else if (K == 2) {
        for (int i = 0; i < N.size(); i++) {
            bool z = true;
            for (int j = i + 1; j < N.size(); j++) {
                if (i == 0 && z) {
                    ans += 1 * (N[j] - '0');
                    ans += (N[i] - '0' - 1) * 9;
                } else if (i == 0) {
                    ans += (N[i] - '0') * 9;
                } else {
                    ans += 9 * 9;
                }
                if (N[j] != '0') z = false;
            }
        }
    } else if (K == 3) {
        for (int i = 0; i < N.size(); i++) {
            bool z0 = true;
            for (int j = i + 1; j < N.size(); j++) {
                bool z1 = true;
                for (int k = j + 1; k < N.size(); k++) {
                    if (i == 0 && z0 && z1) {
                        ans += 1 * (N[j] != '0') * (N[k] - '0');
                        ans += 1 * (N[j] != '0' ? N[j] - '0' - 1 : 0) * 9;
                        ans += (N[i] - '0' - 1) * 9 * 9;
                    } else if (i == 0 && z0) {
                        ans += 1 * (N[j] != '0') * 9;
                        ans += 1 * (N[j] != '0' ? N[j] - '0' - 1 : 0) * 9;
                        ans += (N[i] - '0' - 1) * 9 * 9;
                    } else if (i == 0) {
                        ans += (N[i] - '0') * 9 * 9;
                    } else {
                        ans += 9 * 9 * 9;
                    }
                    if (N[k] != '0') z1 = false;
                }
                if (N[j] != '0') z0 = false;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
