#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);

    vector<vector<int>> cnt(n, vector<int>(26));
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (auto c : s[i]) ++cnt[i][(int)(c - 'a')];
    }

    string res;
    for (char c = 'a'; c <= 'z'; ++c) {
        int min_n = 500;
        for (int i = 0; i < n; ++i)
            min_n = min(min_n, cnt[i][(int)(c - 'a')]);
        if (min_n) res += string(min_n, c);
    }

    cout << res << endl;

    return 0;
}
