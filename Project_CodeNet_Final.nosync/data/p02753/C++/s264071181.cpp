#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    map<char, int> mmp;
    for(int i = 0; i < 3; ++i)
        mmp[s[i]]++;
    if(mmp['A'] == 2 || mmp['B'] == 2) puts("Yes");
    else puts("No");

    return 0;
}