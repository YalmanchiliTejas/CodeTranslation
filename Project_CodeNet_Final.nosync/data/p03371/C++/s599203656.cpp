#include <bits/stdc++.h>
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static const ll MOD=1e9+7;
ll max(ll a, ll b) {return a>b ? a:b;}
ll min(ll a, ll b) {return a<b ? a:b;}


int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    ll ans=0;
    
    if(a+b>=c*2) {
        ans=c*2*min(x, y)+min(a, c*2)*(x-min(x, y))+min(b, c*2)*(y-min(x, y));
    }else {
        ans=a*x+b*y;
    }
    
    pt(ans);
}
