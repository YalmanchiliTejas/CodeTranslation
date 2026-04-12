#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    c*=2;
    int ans=c*max(x,y);
    ans=min(ans,a*x+b*y);
    if(x-y>0)ans=min(ans,a*(x-y)+c*y);
    if(y-x>0)ans=min(ans,b*(y-x)+c*x);
    cout<<ans<<endl;
    return 0;
}
