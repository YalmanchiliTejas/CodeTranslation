#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 100000;
const int MAX_K = 10;

int N;

int ans[MAX_N + 1];

string allocate(string s);
string translate();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    string s;

    cin >> s;

    cout << allocate(s) << "\n";

    return 0;
}

string allocate(string s)
{
    for (int j = 0; j < 4; j++) {
        if (j & 1) {
            ans[0] = 1;
        } else {
            ans[0] = 0;
        }

        if (j & (1 << 1)) {
            ans[1] = 1;
        } else {
            ans[1] = 0;
        }

        for (int i = 1; i < N; i++) {
            if (s[i] == 'o') {
                if (ans[i]) {
                    ans[i + 1] = !ans[i - 1];
                } else {
                    ans[i + 1] = ans[i - 1];
                }
            } else {
                if (ans[i]) {
                    ans[i + 1] = ans[i - 1];
                } else {
                    ans[i + 1] = !ans[i - 1];
                }
            }
        }

        if (ans[N] == ans[0]) {
            if ((s[0] == 'o') && ((ans[0] && ans[N - 1] == !ans[1]) || (!ans[0] && ans[N - 1] == ans[1]))) {
                return translate();
            } else if ((s[0] == 'x') && ((ans[0] && ans[N - 1] == ans[1]) || (!ans[0] && ans[N - 1] == !ans[1]))) {
                return translate();
            }
        }
    }
    return "-1";
}

string translate()
{
    string out = "";
    for (int i = 0; i < N; i++) {
        if (ans[i]) {
            out += 'W';
        } else {
            out += 'S';
        }
    }
    return out;
}