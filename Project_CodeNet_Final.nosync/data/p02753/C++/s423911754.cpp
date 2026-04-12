#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10];
    cin>>a;
    int A=0,B=0;
    for(int i=0;i<=2;i++)
    {
       if(a[i]=='A')
        A++;
       else
        B++;
    }
    if(A&&B)
        cout<<"Yes";
    else
        cout<<"No";
return 0;
}
