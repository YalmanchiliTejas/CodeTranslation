#include <bits/stdc++.h>
using namespace std;

/* define const */

/* finish defineing const */

int n;
string s[55];
int cnt[55][30] = {};
int ans[30] = {};

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    // input

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < s[j].length(); i++)
        {
            cnt[j][s[j][i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        int ct = 100;
        for (int j = 0; j < n; j++)
        {
            ct = min(ct, cnt[j][i]);
        }
        ans[i] = ct;
    }

    for (int i = 0; i < 26; i++)
    {
        while (ans[i] > 0)
        {
            cout << (char)(i + 'a');
            ans[i]--;
        }
    }
    cout << endl;
}
