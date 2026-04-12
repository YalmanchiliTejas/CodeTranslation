#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

#define for0(i,n) for(ll i = 0;i < (n);i++)
#define for1(i,n) for(ll i = 1;i<=(n);i++)
#define for2(i,n) for(ll i = 2;i<=(n);i++)
#define fastio cin.tie(0);cout.tie(0);ios::sync_with_stdio(0)
#define rep(i,st,en,cnt) for(ll i = st;i <= en;i+=cnt)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define bit(x,n) (x & (1<<(n)))
#define EPS 1e-8
#define all(x) (x).begin(),(x).end()
#define INF 0x3f3f3f3f3f3f3f
#define NEGINF -INF
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define inp_arr(a,n) for0(i,n) {cin>>a[i];}
#define out_arr(a,n) for0(i,n) {cout<<a[i]<<" ";}cout<<endl;
#define deb1(a) cout<<(a)<<endl;
#define deb2(a,b) cout<<(a)<<" "<<(b)<<endl;
#define deb3(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl;

using namespace std;

typedef pair<int,int> ii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vl;
typedef vector<vector<ll> > vvl;
typedef vector<pair<long long, long long> > vll;
typedef long double LD;

ii DR8[] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
ii DR4[] = {{-1,0},{0,-1},{0,1},{1,0}};

const ll mod = 998244353;

// ll nop = 2;
// vi primes(nop+1,1);

// void sieve(){
//     primes[1] = primes[0] = 0;
//     for(ll i = 2;i * i <= nop;i++){
//         if(primes[i]){
//             for(ll j = i*i; j <= nop;j+=i){
//                 primes[j] = 0;
//             }
//         }
//     }
// }

// ll phi(ll n) {
//     ll tot = n;
//     for(ll i = 2;i*i <= n;i++) {
//         if(n%i == 0) {
//             tot -= tot/i;
//         }
//         while(n%i == 0) {
//             n /= i;
//         }
//     }
//     if(n > 1) {
//         tot -= tot/n;
//     }
//     return tot;
// }

ll gcd(ll a,ll b){
    if(b>a) swap(b,a);
    if(b==0) return a;
    return gcd(b,a%b);
}

void extgcd(ll a,ll b,ll& x,ll& y){  //a smaller b larger
    if(a==0) {
        x = a;y = b;
        return;
    }
    extgcd(b%a,a,x,y);
    ll y1 = y,x1 = x;
    x = y1 - (b/a)*x1;
    y = x1;
}

ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}

ll bexp(ll num,ll e){
    ll ans = 1;
    while(e>0){
        if(e&1){
            ans *= num;
        }
        num *= num;
        e>>= 1;
    }
    return ans;
}

ll mexp(ll num,ll e){
    ll ans = 1;
    while(e>0){
        if(e&1){
            ans = (ans *num)%mod;
        }
        num *= num;
        num %= mod;
        e>>=1;
    }
    return ans%mod;
}

ll modinv(ll a){
    a %= mod;
    return mexp(a,mod-2);
}

void solve() {
    int k;
    cin>>k;
    if(k >= 30) deb1("Yes")
    else deb1("No")
}

int main() {
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t = 1;
    //cin>>t;
    while(t--) {
        solve();
    }
    /* #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif */
    return 0;
}
