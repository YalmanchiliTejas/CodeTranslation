#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

vector<ll> a;
vector<ll> p;

ll F(ll i, ll j){
    if(i<=0){
        return 1;
    }else{
        if(j<=1) return 0;
        else if(j <= 1+a[i-1]) return F(i-1,j-1);
        else if(j == 2+a[i-1]) return p[i-1]+1;
        else if(j <= 2+2*a[i-1]) return p[i-1]+1+F(i-1,j-2-a[i-1]);
        else return 2*p[i-1]+1;
    }
}

int main(){
    ll n,x;
    cin>>n>>x;
    a.resize(n+1,0);
    p.resize(n+1,0);
    a[0]=1; p[0]=1;
    rep(i,0,n){
        a[i+1]=2*a[i]+3;
        p[i+1]=2*p[i]+1;
    }
    ll ans=F(n,x);
    cout<<ans<<endl;
}