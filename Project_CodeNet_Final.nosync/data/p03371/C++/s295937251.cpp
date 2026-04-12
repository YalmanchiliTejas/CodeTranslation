#include<bits/stdc++.h>
using namespace std;

int a,b,c,x,y;

int main()
{
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    int ans=min(min(x,y)*2*c, (b+a)*min(x, y));
    if(x>y){
        ans+=min(a*(x-y), c*2*(x-y));
    }
    else{
        ans+=min(b*(y-x), c*2*(y-x));
    }
    cout<<ans<<endl;
}
