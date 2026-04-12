#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans = INF;
    ll now = 0;
    for(int i=0;i<=2*max(x,y);i++){
        if(i%2!=0) continue;
        now = 0;
        now += i*c;
        ll aa = x - i/2, bb = y-i/2;
        if(aa<0) aa = 0;
        if(bb<0) bb = 0;
        now+=a*aa+b*bb;
        ans = min(ans,now);
    }
        cout<<ans<<endl;
    

    return 0;
}