#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int s[n][26] = {0};
    string str;
    rep(i, n) {
        cin >> str;
        rep(j, str.size()) ++s[i][str[j] - 'a'];
    }
    string res = "";
    rep(j, 26){
        int min_n = 51;
        rep(i, n) min_n = min(min_n, s[i][j]);
        rep(i, min_n) res += 'a' + j;
    }

    cout << res << endl;

    return 0;
}