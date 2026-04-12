#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;

ll f(ll t,ll p, ll x){
    if(x==0) return 0;
    if(t==1) return 1; 

    if(x<=t/2) return f((t-3)/2, (p-1)/2, x-1);
    else return p/2 + 1 + f((t-3)/2, (p-1)/2, x-t/2-1);
}

int main(){FIN

    ll n,x;cin>>n>>x;
    ll s=1, p=1;
    REP(i,n){
        s= s*2+3;
        p = p*2+1;
    }
    cout<<f(s,p,x)<<endl;
    return 0;
}