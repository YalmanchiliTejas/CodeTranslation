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
    string s;
    cin >> s;

    char cans1[4] = {'S', 'W', 'S', 'W'};
    char cans2[4] = {'S', 'W', 'W', 'S'};

    rep(i, 4) {
        vector<char> ans(N);
        ans[0] = cans1[i], ans[1] = cans2[i];
        for (int i = 2; i < N; i++) {
            if (ans[i - 2] == 'S' && ans[i - 1] == 'S') {
                if (s[i - 1] == 'o')
                    ans[i] = 'S';
                if (s[i - 1] == 'x')
                    ans[i] = 'W';
            }
            if (ans[i - 2] == 'W' && ans[i - 1] == 'W') {
                if (s[i - 1] == 'o')
                    ans[i] = 'S';
                if (s[i - 1] == 'x')
                    ans[i] = 'W';
            }
            if (ans[i - 2] == 'S' && ans[i - 1] == 'W') {
                if (s[i - 1] == 'o')
                    ans[i] = 'W';
                if (s[i - 1] == 'x')
                    ans[i] = 'S';
            }
            if (ans[i - 2] == 'W' && ans[i - 1] == 'S') {
                if (s[i - 1] == 'o')
                    ans[i] = 'W';
                if (s[i - 1] == 'x')
                    ans[i] = 'S';
            }
        }

        bool judge = 1;

        rep(i, N) {
            int a = i - 1, b = i + 1;
            if (i == 0)
                a = N - 1;
            if (i == N - 1)
                b = 0;

            if (ans[i] == 'S' && s[i] == 'o') {
                if (ans[a] != ans[b])
                    judge = 0;
            }
            if (ans[i] == 'S' && s[i] == 'x') {
                if (ans[a] == ans[b])
                    judge = 0;
            }
            if (ans[i] == 'W' && s[i] == 'o') {
                if (ans[a] == ans[b])
                    judge = 0;
            }
            if (ans[i] == 'W' && s[i] == 'x') {
                if (ans[a] != ans[b])
                    judge = 0;
            }
        }

        if (judge) {
            rep(i, N) { cout << ans[i]; }
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}