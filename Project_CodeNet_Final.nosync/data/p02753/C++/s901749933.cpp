
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ca=0,cb=0,i;
    string s;
    cin>>s;
    for(i=0;i<3;i++)
    {
        if(s[i]=='A') ca++;
        if(s[i]=='B') cb++;
    }
    if(ca==2 || cb==2) cout<<"Yes\n";
    else cout<<"No\n";


    return 0;
}
