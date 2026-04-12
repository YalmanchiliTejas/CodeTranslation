#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

const int INF =1e9+7;
int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int n = max(x,y);
    ll ans = INF;
    rep(i,n+1){
        ll cost = 2*i*c+(max(0,x-i))*a + (max(0,y-i))*b;
        ans = min(cost,ans);
    }
    cout<<ans<<endl;
    return 0;
}