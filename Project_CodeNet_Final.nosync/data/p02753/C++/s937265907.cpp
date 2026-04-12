#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;

    char c;
    for (auto i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            c = s.at(i);
            continue;
        }

        if (c != s.at(i))
        {
            cout << "Yes" << endl;
            return 0;
        }
        c = s.at(i);
    }

    cout << "No" << endl;

    return 0;
}
