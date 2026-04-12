#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;int c=0,d=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='A')
            c++;
        else
            d++;
    }
    if(c==3||d==3)
        cout<<"No";
    else
        cout<<"Yes";
}
