#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int c=0;
    for(int i=0; i<s.size(); i++)
    {
        if((s[i]=='A' && s[i+1]=='B') || (s[i+1]=='A' && s[i+2]=='B'))
        {
            c=1;
            break;
        }
    }
    for(int i=0; i<s.size(); i++)
    {
        if((s[i]=='B' && s[i+1]=='A') || (s[i+1]=='B' && s[i+2]=='A'))
        {
            c=2;
            break;
        }
    }
    if(c==1 ||c==2)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
