#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;

    char thes = s[k - 1];

    for (int i = 0; i < n; i++)
    {
        /* code */
        if (s[i] != thes)
        {
            s[i] = '*';
        }
    }
    cout << s << endl;
}