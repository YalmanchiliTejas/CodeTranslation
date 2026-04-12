#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    string s;
    char ch;

    cin >> n >> s >> k;
    ch = s.at(k - 1);

    for (int i = 0; i < n; i++)
    {
        if (s.at(i) != ch)
        {
            s.at(i) = '*';
        }
    }

    cout << s << endl;

    return 0;
}