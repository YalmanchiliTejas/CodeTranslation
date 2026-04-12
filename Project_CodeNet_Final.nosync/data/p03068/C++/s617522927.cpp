
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    string S;
    cin >> N >> S >> K;
    char ch = S[K - 1];
    string res;
    for (auto s: S) {
        if (s == ch) {
            cout << s;
        } else {
            cout << '*';
        }
    }
    cout << '\n';

    return 0;
}
