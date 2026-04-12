#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >>s;
    bool flg=true;
    if(s[0]==s[1]&&s[0]==s[2])flg=false;
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}
