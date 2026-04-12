#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    if (s.compare("AAA") == 0 || s.compare("BBB") == 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}