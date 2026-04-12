#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

bool dp[30009][4][1009];

int main(void)
{
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=INF;
    rep(i,1e5+1){
        ll tmp = 2*c*i + max(0LL, x-i)*a + max(0LL, y-i)*b;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}