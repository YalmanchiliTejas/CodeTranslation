#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c=0,cc=0;
    string s;cin>>s;

    for(int  i=0;i<s.size();i++)
    {
        if(s[i]=='A')
            c++;
        else
            cc++;
    }
    if(c>0&&cc>0)
        cout<<"Yes\n";
    else cout<<"No\n";
}
