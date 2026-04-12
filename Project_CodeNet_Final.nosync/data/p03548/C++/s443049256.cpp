#include<iostream>
using namespace std;
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    int a,b,ans=0;
    a=x-z;
    b=y+z;
    ans=a/b;
    cout<<ans;
    system("pause");
    return 0;
}