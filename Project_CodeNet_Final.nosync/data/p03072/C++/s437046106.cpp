#include<iostream>
using namespace std;
int main()
{
    int n,h,m,ans=1;
    cin>>n;
    cin>>m;
    for(int i=1;i<n;i++)
    {
        cin>>h;
        if(h>=m) ans++,m=h;
    }
    cout<<ans<<endl;
    return 0;
}