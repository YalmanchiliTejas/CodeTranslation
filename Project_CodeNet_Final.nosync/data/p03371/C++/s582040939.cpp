#include<bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    c*=2;
    int ans=a*x+b*y;
    ans=min(ans,c*max(x,y));
    if(y-x>0)ans=min(ans,c*x+b*(y-x));
    if(x-y>0)ans=min(ans,c*y+a*(x-y));
    cout<<ans<<endl;
    return 0;
}
