#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;

    int ans[26] = {};
    REP(i, 0, N) {
        string s; cin >> s;
        if (i == 0) {
            REP(j, 0, s.size()) {
                ans[s[j] - 'a']++;
            }
        } else {
            int tmp[26] = {};
            REP(j, 0, s.size()) {
                tmp[s[j] - 'a']++;
            }
            REP(j, 0, 26) {
                ans[j] = min(ans[j], tmp[j]);
            }
        }
    }

    REP(i, 0, 26) {
        REP(j, 0, ans[i]) {
            cout << char(i + 'a');
        }
    }
    cout << endl;
    return 0;
}