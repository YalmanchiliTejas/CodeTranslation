#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    char c=s[0];
    int i;
    for(i=1;i<s.length();i++)
    {
        if(s[i]!=c)
        {
            cout<<"Yes"<<endl;
            break;
        }
        
    }
    if(i==s.length())
        cout<<"No"<<endl;
    return 0;
}