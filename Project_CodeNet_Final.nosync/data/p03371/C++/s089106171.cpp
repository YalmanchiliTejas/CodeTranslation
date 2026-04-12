#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    int ans=0;
    int z=min(x,y);
    ans+=z*min(a+b,c*2);
    if(x<y)ans+=(y-z)*min(b,c*2);
    else if(x>y)ans+=(x-z)*min(a,c*2);
    cout<<ans<<endl;
}
