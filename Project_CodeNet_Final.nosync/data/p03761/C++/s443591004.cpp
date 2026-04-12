#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n, i, j;
    cin >> n;
    vector<int> cnt(26, 0);
    string t;
    cin >> t;
    for (i = 0; i < t.size(); i++)
    {
        cnt.at(t.at(i) - 'a')++;
    }
    for (i = 1; i < n; i++)
    {
        string s;
        cin >> s;
        vector<int> cnt2(26, 0);
        for (j = 0; j < s.size(); j++)
        {
            cnt2.at(s.at(j) - 'a')++;
        }
        for (j = 0; j < 26; j++)
        {
            cnt.at(j) = min(cnt.at(j), cnt2.at(j));
        }
    }
    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < cnt.at(i); j++)
        {
            cout << (char)('a' + i);
        }
    }
    cout << endl;
}