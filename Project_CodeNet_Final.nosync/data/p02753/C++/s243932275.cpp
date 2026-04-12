#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
const int64_t BIG_PRIME = 1000000007;

int main()
{
    char s[3];
    cin >> s;

    if (s[0] == s[1] && s[1] == s[2])
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}