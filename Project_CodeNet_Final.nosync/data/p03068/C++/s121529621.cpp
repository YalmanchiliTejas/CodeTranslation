//Tenka1 Programmer Beginner Contest 2019
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    string s = {};
    char c[15] = {};
    string r = {};
    cin >> n >> s >> k;
    //cout << s[k] << endl;
    for (int i = 0; i < n; i++)
    {
        c[i] = s[i];
        if (c[i] != s[k - 1])
        {
            c[i] = '*';
        }
    }
    for (int i = 0; i < n; i++)
    {
        r += c[i];
    }

    cout << r << endl;
}
