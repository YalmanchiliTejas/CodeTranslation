#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+5;

int a,b,c,x,y;
long long ans1=0,ans2=0,ans3=0,ans=0;
int main()
{
    cin>>a>>b>>c>>x>>y;
    ans1=x*a+y*b;
    if(x<y)
    {
        ans2+=2*x*c;
        ans3+=2*x*c;
        y-=x;
        ans2+=b*y;
        ans3+=2*y*c;
    }
    else
    {
        ans2+=2*y*c;
        ans3+=2*y*c;
        x-=y;
        ans2+=a*x;
        ans3+=2*x*c;
    }
    ans=min(ans1,ans2);
    ans=min(ans,ans3);
    cout<<ans<<endl;
    return 0;
}