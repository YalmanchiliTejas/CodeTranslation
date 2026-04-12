#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    int N;
    cin >> N;
    vector<char> ans;
    vector<vector<int>> A(26, vector<int>(N, 0));
    rep(i, N) {
        string s;
        cin >> s;
        rep(j, s.size()) {
            int a = s[j] - 'a';
            A[a][i]++;
        }
    }

    rep(i, 26) {
        bool judge = 1;
        int num = 1e9;
        rep(j, N) {
            if (A[i][j] == 0) {
                judge = 0;
                break;
            }
            num = min(num, A[i][j]);
        }

        if (judge) {
            rep(k, num) { ans.push_back(i + 'a'); }
        }
    }

    sort(all(ans));
    rep(i, ans.size()) { cout << ans[i]; }
    cout << endl;
}