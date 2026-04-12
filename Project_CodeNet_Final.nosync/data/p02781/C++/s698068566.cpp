#include <bits/stdc++.h>
using namespace std;
string N;
bool f(string a) {
    if (a.length() < N.length()) {
        return 1;
    }
    if (a.length() > N.length()) {
        return 0;
    }
    return a <= N;
}
int main () {
    cin >> N;
    int K;
    cin >> K;
    vector<string> A[3][110];
    long long ans;
    ans = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 0;; j++) {
            string g = to_string(i)+string(j, '0');
            if (f(g)) {
                A[0][g.length()].push_back(g);
                ans++;
            }
            else {
                break;
            }
        }
    }
    if (K == 1) {
        cout << ans << endl;
    }
    ans = 0;
    for (int i = 0; i <= N.length(); i++) {
        for (int j = 0; i+j <= N.length(); j++) {
            for (auto x: A[0][i]) {
                for (auto y: A[0][j]) {
                    auto g = x+y;
                    if (f(g)) {
                        A[1][g.length()].push_back(g);
                        ans++;
                    }
                }
            }
        }
    }
    if (K == 2) {
        cout << ans << endl;
    }
    ans = 0;
    for (int i = 0; i <= N.length(); i++) {
        for (int j = 0; i+j <= N.length(); j++) {
            if (i + j < N.length()) {
                ans += A[0][i].size() * A[1][j].size();
                continue;
            }
            for (auto x: A[0][i]) {
                for (auto y: A[1][j]) {
                    auto g = x+y;
                    if (f(g)) {
                        ans++;
                    }
                }
            }
        }
    }
    if (K == 3) {
        cout << ans << endl;
    }
}