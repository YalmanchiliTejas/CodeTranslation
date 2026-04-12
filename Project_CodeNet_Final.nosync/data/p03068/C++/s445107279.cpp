#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, k;
    string s;
    cin >> a >> s >> k;
    k--;
    for (int i = 0; i < a; i++)
    {
        if (s[i] != s[k])
        {
            s[i] = '*';
        }
    }
    cout << s;
    return 0;
}
