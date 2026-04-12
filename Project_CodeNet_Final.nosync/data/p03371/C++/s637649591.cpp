#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int cst1=0,cst2=0;
    int mi=min(x,y);
    cst1+=mi*2*c;
    cst1+=(x-mi)*a+(y-mi)*b;
    cst2=x*a+y*b;
    int ma=max(x,y);
    int cst3=ma*2*c;
    int ans=min(cst1,cst2);
    ans=min(cst3,ans);
    cout<<ans;
}
