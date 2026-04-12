#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s; int x=0,y=0;
    cin>>s;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='A')
            x++;
        else
            y++;
    }
    if(x!=0 && y!=0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
