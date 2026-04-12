#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1

ll mod_add(ll a, ll b) { return (a + b) % MOD; }
ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return a*b % MOD; }

ll n,l,r;

bool check(ll y,const vector<ll> &v){
    bool res;
    rep(i,v.size()){    
        if(y % v[i] == 0)return i%2 == 0;
    }
    return v.size()%2 == 0;
}

int main(){
    while(cin >> n >> l >> r && n){
        vector<ll> v(n);
        rep(i,n)cin >> v[i];
        ll ans = 0;
        for(ll i = l;i <= r;i++){
            if(check(i,v))ans++;
        }
        cout << ans << endl;
    }
}
