#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define fi first
#define se second
#define For(i,a,b) for(ll i=a;i<b;i++)
#define RFor(i,b,a) for(ll i = b;i>=a;i--)
#define sz size()
#define PQ priority_queue
#define len length()
#define mll map<ll,ll>
#define mpll map<pll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pair<ll,ll> >
#define mp(x,y)  make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back
#define pf push_front
#define ALL(v) v.begin(),v.end()
#define LAPAK ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const ll MOD = 2*(1e9 + 7);
const ll INF = 2e18;
const ll MAX = 405;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    LAPAK
    
    ll n;
    cin>>n;
    ll a[n];
    For(i,0,n)cin>>a[i];
    ll s1 = 0,s2 = 0;
    For(i,0,n){
        s1 += a[i];
        s2 += binpow(a[i],2,MOD);
        s1 %= MOD;
        s2 %= MOD;
        //cout<<s1<<" "<<s2<<endl;
    }
    
    ll s3 = binpow(s1,2,MOD);
    //cout<<s3<<" "<<s2<<endl;
    ll ans = (s3-s2 + MOD)/2;
    cout<<(ans+MOD)%(MOD/2);
    
    return 0;
}