#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    set<char> ss;
    for (int i = 0; i < s.size(); i++)
        ss.insert(s[i]);
    if (ss.size() > 1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}