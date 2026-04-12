#include <bits/stdc++.h>
using namespace std;

void fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}
int main() 
{   
    fast();
    string s;
    cin>>s;
    int ok1=0,ok2=0;
    for(int i=0;i<3;i++)
    {
        if(s[i]=='A')
            ok1=1;
        if(s[i]=='B')
            ok2=1;
    }
    if(ok1+ok2==2)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}