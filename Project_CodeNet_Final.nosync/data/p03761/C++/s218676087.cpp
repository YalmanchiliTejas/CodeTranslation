#include <bits/stdc++.h>
using namespace std;

int table[50][26];

int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            int k = s[j] - 'a';
            table[i][k]++;
        }
    }
    for (int j = 0; j < 26; j++)
    {
        int k = INT_MAX;
        for (int i = 0; i < n; i++)
            k = min(k, table[i][j]);
        char c = j + 'a';
        for (int i = 0; i < k; i++)
        {
            cout << c;
        }
    }
    cout << endl;
}
