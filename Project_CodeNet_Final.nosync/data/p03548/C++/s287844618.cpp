#include<bits/stdc++.h>
using namespace std;
int x,y,z,a,ans;
int main()
{
    cin>>x>>y>>z;
    a=z;
    while(a+y+z<=x)
    {
        a+=y+z;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}