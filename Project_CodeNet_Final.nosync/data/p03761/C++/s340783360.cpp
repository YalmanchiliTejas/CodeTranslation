#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 50, INDEX = 1;
const int MAX_LENGTH = 50, INF = MAX_LENGTH + 1;
const int ALPHA = 26;

int n, countersOfChars[ALPHA], minCountersOfChars[ALPHA];

string s[MAX_N + INDEX], ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < ALPHA; i++) {
        minCountersOfChars[i] = INF;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < ALPHA; j++) {
            countersOfChars[j] = 0;
        }

        for (int j = 0; j < s[i].length(); j++) {
            countersOfChars[s[i][j] - 'a']++;
        }

        for (int j = 0; j < ALPHA; j++) {
            minCountersOfChars[j] = min(minCountersOfChars[j], countersOfChars[j]);
        }
    }

    for (int i = 0; i < ALPHA; i++) {
        for (int j = 0; j < minCountersOfChars[i]; j++) {
            ans += i + 'a';
        }
    }

    cout << ans << endl;

    return 0;
}
