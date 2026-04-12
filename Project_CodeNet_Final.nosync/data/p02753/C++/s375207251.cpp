#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=0,b=0,i;
    char ch;
    for(i=0;i<3;i++)
    {
        cin>>ch;
        if(ch=='A')
        a++;
        else 
        b++;
    }
    if(a!=0&&b!=0)
    cout<<"Yes\n";
    else cout<<"No\n";
}