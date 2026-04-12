#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

ll modinv(ll a, ll m) {
    ll b=m,u=1,v=0;
    while(b){
        ll t = a/b;
        a -= t*b; swap(a,b);
        u -= t*v; swap(u,v);
    }
    u %= m;
    if (u<0) u += m;
    return u;
}

void kaijou(vector<ll> &vec) {
    vec.resize(1001001);
    vec[0]=1;
    rep(i,1001000) vec[i+1]=(vec[i]*(i+1))%MOD;
    return;
}

vector<ll> kai;
ll comb(int x,int y){
    if(x<y || y<0)  return 0;
    return kai[x]*modinv(kai[x-y]*kai[y],MOD)%MOD;
}

int main() {
    kaijou(kai);
    ll n,m,k;
    cin>>n>>m>>k;
    
    ll ans=0;
    for(ll i=0; i<n; i++) {
        ans+=i*(n-i)*m*m%MOD;
        ans%=MOD;
    }
    for(ll i=0; i<m; i++) {
        ans+=i*(m-i)*n*n%MOD;
        ans%=MOD;
    }
    ans*=comb(n*m-2,k-2);
    ans%=MOD;
    
    cout<<ans<<endl;
}
