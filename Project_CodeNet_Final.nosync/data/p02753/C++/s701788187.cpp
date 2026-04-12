#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int a = 0;
    int b = 0;

    for (auto x : s)
    {
        if (x == 'A')
            a++;
        else
            b++;
    }

    if (a != 3 && b != 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
