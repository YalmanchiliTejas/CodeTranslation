#include <bits/stdc++.h>

using namespace std;
//FILE *fi=freopen("1.txt","r",stdin);
string s;
bool ok1,ok2;
int main()
{
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='A')
            ok1=true;
        else
            ok2=true;
    }
    ok1==ok2&&ok1==true ? cout<<"Yes" : cout<<"No";
    return 0;
}
