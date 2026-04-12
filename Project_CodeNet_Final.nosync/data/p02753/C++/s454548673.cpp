#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int a=0,p=0;
    cin>>s;
    for(int i=0;i<3;i++)
    {
        if(s[i]=='A')
            a++;
        if(s[i]=='B')
            p++;
    }
    if(a>=1&&p>=1)
        cout<<"Yes";
    else
        cout<<"No";
    cout<<"\n";
    return 0;

}
