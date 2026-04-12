#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const ll mod = 1e9 + 7;
const ll maxn = 2e5 + 5;
const double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078;
//iostream::sync_with_stdio(false);

int main()
{
    string s;
    cin >> s;
    if(s[0] == s[1] || s[0] == s[2] || s[1] == s[2])
    {
        if(s[0] == s[1] && s[1] != s[2])
        {
            cout << "Yes" << endl;
        }
        else if(s[0] == s[2] && s[0] != s[1])
        {
            cout << "Yes" << endl;
        }
        else if(s[1] == s[2] && s[0] != s[1])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
