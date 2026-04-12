#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,d,e,f,g,h,i,j;
    long long int x,y;
    cin>>a>>b>>c>>x>>y;
  d=a+b;
  e=2*c;
    e=min(d,e);
    f=min(x,y);
    x-=f;
    y-=f;
    g=min(a,2*c);
    h=min(b,2*c);
    long long int ans=0,sum=0;
    ans=f*e;

    if(x>0)
    {
        ans+=g*x;
    }
    if(y>0)
    {
        ans+=h*y;
    }
    cout<<ans<<endl;
    return 0;
}

