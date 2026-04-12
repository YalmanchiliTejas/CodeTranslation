#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int conA=0, conB=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')
            conA++;
        if(s[i]=='B')
            conB++;
    }
    if(conA==1 && conB==2)
        cout <<"Yes";
    else if(conA==2 && conB==1)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
