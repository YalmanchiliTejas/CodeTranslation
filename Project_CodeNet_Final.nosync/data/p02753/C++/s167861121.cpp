#include<bits/stdc++.h>
using namespace std;
int main()
{
    int flag1,i;
    string s;
    cin >>s;
    flag1=1;
        for (i=1;i<s.length();i++)
        {
            if(s[i]!=s[0])
            {
                 flag1=0;
                 break;
            }
        }
    if(flag1==1)cout<<"No";
    else cout<<"Yes";
}
