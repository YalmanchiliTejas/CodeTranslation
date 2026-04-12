#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
ll a,b,c,x,y;
int main(){
    cin>>a>>b>>c>>x>>y;
    ll ans = INF;
    ll now = 0;
    for(ll i = 0;i <= 2*max(x,y);i++){
        now = 0;
        if(i%2!=0) continue;
        now += i*c;
        ll aa = x-i/2,bb = y-i/2;
        if(aa<0) aa = 0;
        if(bb<0) bb = 0;
        now+=a*aa+b*bb;
        //cout<<i<<endl;
        //cout<<now<<endl<<endl;

        ans = min(now,ans);
    }
    cout << ans << endl;
    return 0;
}