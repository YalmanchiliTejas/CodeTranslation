#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[4];
    cin>>s;
    if(s[0]==s[1] && s[1]==s[2] && s[2]==s[1])
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    return 0;
}
