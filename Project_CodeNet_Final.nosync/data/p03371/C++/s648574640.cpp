#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    int ans=0;
    if(a+b>c*2){
        int t=min(x,y);
        ans+=t*c*2;
        x-=t;
        y-=t;
    }else{
        ans+=a*x+b*y;
        cout<<ans<<endl;
        return;
    }
    ans+=min(x*a+y*b,(x+y)*2*c);
    cout<<ans<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}