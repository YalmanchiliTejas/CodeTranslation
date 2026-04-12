#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    int N;
    string s;
    cin >> N >> s;

    vector<char> candidate = {'S', 'W', 'S', 'W'};
    vector<char> last_candidate = {'S', 'S', 'W', 'W'};
    string ans = "-1";
    rep(k, 4) {
        vector<char> a(N);
        char start = candidate[k];
        char last = last_candidate[k];
        a[0] = start;
        rep(i, N) {
            char prev = last;
            if (i > 0) prev = a[i - 1];
            int n_i = (i + 1) % N;

            if (a[i] == 'S' && s[i] == 'o') {
                a[n_i] = prev;
            } else if (a[i] == 'W' && s[i] == 'o') {
                if (prev == 'S') a[n_i] = 'W';
                else a[n_i] = 'S';
            } else if (a[i] == 'S' && s[i] == 'x') {
                if (prev == 'S') a[n_i] = 'W';
                else a[n_i] = 'S';
            } else {
                a[n_i] = prev;
            }
        }

        if (a[a.size() - 1] == last && a[0] == start) {
            ans = string(a.begin(), a.end());
            break;
        }
    }

    cout << ans << endl;
}