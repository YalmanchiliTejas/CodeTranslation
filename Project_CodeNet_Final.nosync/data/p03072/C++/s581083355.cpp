#include<iostream>
using namespace std;
int n,h[2001],ans;
bool check(int x)
{
    for(int i=x-1;i>=1;i--)
    {
        if(h[i]>h[x])return 0;
    }
    return 1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<=n;i++)ans+=check(i);
    cout<<ans;
    return 0;
}