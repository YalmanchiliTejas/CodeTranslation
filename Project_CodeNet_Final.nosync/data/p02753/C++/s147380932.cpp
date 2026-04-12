#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    
    int cnta=0,cntb=0,i;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='A')
            cnta++;
        else
            cntb++;
    }
    
    if(cnta>0 && cntb>0)
        cout<<"Yes";
    else
         cout<<"No";

    return 0;
}