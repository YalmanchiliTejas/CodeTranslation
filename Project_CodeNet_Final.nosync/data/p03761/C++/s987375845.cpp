#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    vector<vector<int>> alpha(N, vector<int>(26, 0));
    rep(i, N) {
        string s;
        cin >> s;
        rep(j, s.size()) { alpha[i][s[j] - 'a']++; }
    }

    string s = "";
    rep(j, 26) {
        int cnt = 10000;
        bool judge = 1;
        rep(i, N) {
            if (alpha[i][j] == 0)
                judge = 0;
            cnt = min(cnt, alpha[i][j]);
        }
        if (judge) {
            s += string(cnt, (j + 'a'));
        }
    }

    cout << s << endl;
}