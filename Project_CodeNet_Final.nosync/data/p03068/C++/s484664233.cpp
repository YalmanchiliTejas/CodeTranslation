#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> s >> k;

    for (size_t i = 0; i < n; i++)
    {
        if (s[i] != s[k - 1])
        {
            s[i] = '*';
        }
    }
    cout << s << endl;
    return 0;
}