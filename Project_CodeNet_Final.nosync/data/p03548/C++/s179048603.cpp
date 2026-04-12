#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int a,b,c,x,ans;
    cin>>a>>b>>c;
    int i;
    a-=c;
    x=b+c;
    ans=a/x;
    cout<<ans<<endl;
    return 0;

}