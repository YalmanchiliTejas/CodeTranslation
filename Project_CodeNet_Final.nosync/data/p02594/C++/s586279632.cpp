#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector <vll> vvll;
typedef pair <ll,ll> pll;
typedef vector <pll> vpll;

#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back
#define newl '\n'
#define gcd __gcd
#define fo(i,k,n) for(ll i=k;i<n;i++)
#define rev(i,k,n) for(ll i=k;i>n;i--)
#define MOD 1000000007 //10^9 + 7
#define deb(x) cout<<x<<" "<<#x<<newl
#define all(x) x.begin(),x.end()
#define print(x) for(auto i=x.begin();i!=x.end();i++)cout<<*i<<' ';cout<<endl;

ll INF = 1000000000000000005LL;

ll power(ll x, ll y, ll p=MOD){ //positive y
    ll res = 1;
    x = x % p; 
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 

ll inverse(ll a,ll m=MOD){
    return power(a,m-2,m);
}

vvll matmul(const vvll &a,const vvll &b,ll M=MOD){
    ll n=a.size(),m=a[0].size(),l=b[0].size();
    assert(m==b.size());
    vvll c(n,vll(l,0));
    fo(i,0,n)
    fo(j,0,l)
    fo(k,0,m)
    {
        c[i][j]=(c[i][j]+a[i][k]*b[k][j])%M;
    }
    return c;
}

vvll matpow(vvll a,ll p,ll M=MOD){
    assert(a.size()==a[0].size());
    ll n=a.size();
    vvll res(n,vll(n,0));
    fo(i,0,n)   res[i][i]=1;
    while(p>0)
    {
        if(p&1) res=matmul(res,a,M);
        a=matmul(a,a,M);
        p>>=1;
    }
    return res;
}

void solve(){
    ll n;
    cin>>n;

    if(n>=30) cout<<"Yes";
    else cout<<"No";
}

int main() {
    
    // fast io
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    //Number of Test cases
    ll T=1; 
    //cin>>T;
    
    while(T--){
        solve();
    }
    
    return 0;
}
