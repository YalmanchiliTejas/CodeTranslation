#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,count=0,count1=0;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='A')
        {
            count++;
        }
        else if(s[i]=='B')
        {
            count1++;
        }
    }
    if(count==s.size() || count1==s.size() )
    {
        cout<<"No";
    }
    else
        cout<<"Yes";
}
