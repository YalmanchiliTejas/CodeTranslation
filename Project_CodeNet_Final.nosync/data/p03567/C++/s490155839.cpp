#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;

    auto ndx = s.find("AC");

    if(ndx == string::npos) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}