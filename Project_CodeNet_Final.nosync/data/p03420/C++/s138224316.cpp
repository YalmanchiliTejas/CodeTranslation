#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const ll INF=2e18;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    ll n,k;
    cin >> n >> k;
    ll ans=0;
    repr(i,1,n+1) {
        ll p=(n+1)/i;
        ll r=(n+1)%i;
        ll c=(i-k>0)?i-k:0;
        ll d=(r-k>0)?r-k:0;
        ans+=p*c+d;
        if (k==0) --ans;
    }
    cout << ans << endl;

    return 0;
}
