#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    static int cntmin[26];
    fill(cntmin, cntmin + 26, INF);

    for (int i = 0; i < n; ++i) {
        int cnt[26] = {0};
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); ++i)
            cnt[s[i] - 'a']++;
        for (int i = 0; i < 26; ++i)
            cntmin[i] = min(cnt[i], cntmin[i]);
    }

    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < cntmin[i]; ++j)
            cout << (char)('a' + i);
    cout << endl;
    return 0;
}
