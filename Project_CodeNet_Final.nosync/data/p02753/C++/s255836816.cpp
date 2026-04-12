#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='A' && s[i+1]=='B' ||s[i]=='B' &&s[i+1]=='A')
        {
            cout<<"Yes"<<endl;
            break;
        }
        else if(s[i]=='B' && s[i+1]=='B' || s[i]=='A' &&s[i+1]=='A')
        {
            continue;
        }
        else
        cout<<"No"<<endl;
    }
}