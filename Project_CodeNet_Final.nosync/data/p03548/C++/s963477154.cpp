#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    x-=z*2;
    int ans=0;
    for(int i=1 ; i<=INT_FAST32_MAX ; i++)
    {
        if(i*y+(i-1)*z>x)
        {
            ans=i;
            break;
        }
    }
    ans--;
    cout<<ans<<endl;
    return 0;
}