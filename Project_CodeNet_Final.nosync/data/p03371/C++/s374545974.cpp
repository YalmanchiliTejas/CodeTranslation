#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

const ll INF = 1e9+7;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int m = max(x,y);
    ll ans=INF;
    for(int i=0;i<=m;i++){
        ll tans = i*2*c+max(x-i,0)*a+max(y-i,0)*b;
        ans = min(tans,ans);
    }
    cout<<ans<<endl;
}