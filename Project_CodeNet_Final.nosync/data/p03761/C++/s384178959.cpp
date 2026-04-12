#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 51;
int n;
int cnt[N][26];
int mcnt[26];
string s, ans;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < s.length(); ++j) {
            ++cnt[i][s[j] - 'a'];
        }
    }
    for (int i = 0; i < 26; ++i) {
        mcnt[i] = 1e9;
        for (int j = 0; j < n; ++j) {
            mcnt[i] = min(mcnt[i], cnt[j][i]);
        }
    }
    for (int i = 0; i < 26; ++i) {
        while (mcnt[i]) {
            ans.push_back('a' + i);
            --mcnt[i];
        }
    }
    cout << ans << endl;
    return 0;
}
