#include <iostream>
using namespace std;
long long a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,ans;
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        if((i+1)%15==0)
        {
            ans-=200;
        }
        ans+=800;
    }
    cout<<ans<<endl;
    return 0;
}