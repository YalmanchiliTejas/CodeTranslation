#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    string S[N];
    rep(i, N) cin >> S[i];

    int num[30] = {};
    for (int i = 0; i <= 'z' - 'a'; i++) {
        char c = 'a' + i;
        rep(n, N) {
            int num_c = 0;
            rep(k, S[n].size()) if (S[n][k] == c) num_c++;

            if (n == 0) num[i] = num_c;
            else num[i] = min(num[i], num_c);
        }
    }

    string ans = "";
    for (int i = 0; i<='z' - 'a'; i++) {
        char c = 'a' + i;
        ans.append(num[i], c);
    }

    cout << ans << endl;

    return 0;
}