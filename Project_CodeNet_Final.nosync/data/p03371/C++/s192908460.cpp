#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0;i<(int)n;i++)
ll mod=1e9+7;
#define PI acos(-1)
struct edge{int from, to;};

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int ans=a*x+b*y;
    int ans2,ans3;
    if(x<y){
        ans2=2*c*x+(y-x)*b;
        ans3=2*c*y;
    }
    else{
        ans2=a*(x-y)+2*y*c;
        ans3=2*c*x;
    }
    ans=min(ans, ans2);
    ans=min(ans, ans3);
    cout<<ans<<endl;
    return 0;
}