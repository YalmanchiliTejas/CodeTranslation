#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    string s;
    cin >> N >> s >> K;

    string res = s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != s[K - 1]) res[i] = '*';
    }
    cout << res << endl;
    return 0;
}
