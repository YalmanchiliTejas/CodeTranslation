#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int dp[1000] = {};

int count(string num) {
    // cout << "# num : " << num << endl;
    if (dp[stoi(num)] != 0) return dp[stoi(num)];

    int ans = 0;
    string s(num.size(), '1');
    for (int n = stoi(s); n <= stoi(num); n++) {
        if (to_string(n).find('0') == string::npos) ans++;
    }

    // cout << "## num : " << num << " ans : " << ans << endl;
    return dp[stoi(num)] = ans;
}

int main() {
    string N; cin >> N;
    int K; cin >> K;

    if (K > N.size()) {
        cout << 0 << endl;
        return 0;
    }

    string S(N.size(), '0');
    REP(i, 0, K) S[S.size() - 1 - i] = '1';

    ll ans = 0;
    string prev;
    while (1) {
        string num = "";
        if (S[0] == '1') {
            num += N[0];
            bool a = true;
            REP(i, 1, N.size()) {
                if (S[i] == '1') {
                    if (a) num += N[i];
                    else num += '9';
                } else if (N[i] != '0') {
                    a = false;
                }
            }
        } else {
            REP(i, 0, K) num += '9';
        }

        ans += count(num);

        prev = S;
        next_permutation(ALL(S));
        if (prev >= S) break;
    }

    cout << ans << endl;
    return 0;
}