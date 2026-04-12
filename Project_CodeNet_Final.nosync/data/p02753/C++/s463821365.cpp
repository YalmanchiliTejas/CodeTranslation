#include <bits/stdc++.h>

using namespace std;
char a[4];
int main()
{
    int A=0,B=0;
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
        if(a[i]=='A')
            A++;
        if(a[i]=='B')
            B++;
    }
    if( A>0 && B>0)
    {
        cout<<"Yes";
    }
    else
        cout<<"No";
    return 0;
}