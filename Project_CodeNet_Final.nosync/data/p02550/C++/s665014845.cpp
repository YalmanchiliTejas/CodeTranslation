#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define pp pair<ll,ll>
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
int inf=1000001000;
ll INF=1e18;
ll mod=1000000007;
ll MOD=998244353;

int main() {
    ll n,x,m;
    cin >> n >> x >> m;
    ll c=1,su=x,cc,se;
    map<ll,pair<ll,ll>> s;
    s[x]=mk(0,0);
    while(true){
        if (c==n){
            cout << su << endl;
            return 0;
        }
        ll u=x*x%m;
        if (s.find(u)!=s.end()){
            cc=c-s[u].first;
            se=su-s[u].second;
            x=u;
            break;
        }
        s[u]=mk(c,su);
        c++;
        su+=u;
        x=u;
    }
    ll ans=s[x].second+(n-s[x].first)/cc*se;
    if ((n-s[x].first)%cc!=0){
        ll w=x;
        rep(i,(n-s[x].first)%cc){
            ans+=w;
            w=w*w%m;
        }
    }
    cout << ans << endl;
}
