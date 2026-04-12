#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int alpha[n]['z' - 'a' + 1];
    for (int x = 'a'; x <= 'z'; x++)
    {
        for (int j = 0; j < n; j++)
        {
            alpha[j][x - 'a'] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int x = 0; x < s.size(); x++)
        {
            for (int j = 'a'; j <= 'z'; j++)
            {
                if (s[x] == (char)j)
                {
                    alpha[i][j - (int)'a'] += 1;
                }
            }
        }
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        int min = 50;
        for (int j = 0; j < n; j++)
        {
            if (alpha[j][i - 'a'] < min)
            {
                min = alpha[j][i - 'a'];
            }
        }
        for (int j = 0; j < min; j++)
        {
            cout << (char)i;
        }
    }

    cout << endl;
    return 0;
}