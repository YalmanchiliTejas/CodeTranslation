#include <bits/stdc++.h>

#define rep(n, i) for (int i = 0; i < (n); ++i)

using ll = long long;
using namespace std;

int
main ()
{
    string s;
    cin >> s;

    bool answer = (s == "AAA") || (s == "BBB");

    cout << (answer ? "No" : "Yes") << endl;
}
