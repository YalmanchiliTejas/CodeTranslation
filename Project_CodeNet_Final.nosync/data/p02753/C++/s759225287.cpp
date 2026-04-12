#include <bits/stdc++.h>
using namespace std;

string s;
bool a = false, b = false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
        {
            a = true;
        }
        if (s[i] == 'B')
        {
            b = true;
        }
    }

    if (a && b)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}