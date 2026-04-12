#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _abs(x)((x) < 0 ? (x) * -1 : (x))

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //freopen("debug.txt", "w", stderr);

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    string s;

    cin >> n;

    vector<vector<int> > table(n, vector<int>(26));
    bool doesShare;
    int x;
    string ans = "";

    int i, j, len;
    char ch;

    for (i = 0; i < n; i++) {
        cin >> s;

        len = s.size();
        for (j = 0; j < len; j++) {
            ch = s[j] - 'a';

            table[i][ch]++;
        }
    }

    for (i = 0; i < 26; i++) {
        doesShare = true;
        x = INT_MAX;
        for (j = 0; j < n; j++) {
            if (table[j][i]) {
                x = min(table[j][i], x);
            } else {
                doesShare = false;

                break;
            }
        }

        if (doesShare) ans += string(x, (char)(i + 'a'));
    }

    cout << ans << endl;

    return 0;
}
