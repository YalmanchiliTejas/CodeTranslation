#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    string s;
    cin >> s;
    bool flg = false;
    rep(i, 0, s.length())
    {
        if (s[i] == 'A' && s[i + 1] == 'C')
        {
            flg = true;
        }
    }
    if (flg)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
