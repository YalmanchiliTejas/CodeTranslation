                                          //         PAR_YUMMM            //
                                           //           CPP                //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
ll const N=1e6+5;
ll const INF=9223372036854775807;

#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define si size()
#define be begin()
#define en end()
#define all(v) v.be, v.en
#define len length()
#define mp make_pair
#define mt make_tuple
#define umap unordered_map
#define uset unordered_set
#define acc(v) accumulate(all(v), 0)
#define F first
#define S second
 
#define forz(i, n) for (ll i = 0; i < n; i++)
#define fore(i, m, n) for (ll i = m; i <= n; i++)
#define rforz(i, n) for (ll i = n - 1; i >= 0; i--)
#define rfore(i, m, n) for (ll i = n; i >= m; i--)
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define highll(n) __builtin_popcountll(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define mod2 998244353
#define gcd __gcd
#define sexy ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
 
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ofk order_of_key
#define fbo find_by_order

ll po(ll a,ll b,ll m){
    ll res=1;
    while(b>0){
        if(b&1){
            res=((res%m)*(a%m))%m;
        }
        a=((a%m)*(a%m))%m;
        b>>=1;
    }
    return res;
}

ll modi(ll a,ll m){
    return po(a,m-2,m);
}

ll lcm(ll a,ll b){ 
    return (a*b)/(gcd(a, b));
}

ll max(ll a,ll b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

ll min(ll a,ll b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

ll bins(ll ar[],ll l,ll r,ll x){ 
    if(r>=l){ 
        ll m=l+((r-l)/2); 
        if(ar[m]==x){
            return m; 
        }else if(ar[m]>x){ 
            return bins(ar,l,m-1,x);
        }else{
            return bins(ar,m+1,r,x); 
        }
    } 
    return -1; 
} 

ll nCr(ll n,ll k){ 
    ll C[n + 1][k + 1]; 
    ll i, j; 
    for(i=0;i<=n;i++){ 
        for(j=0;j<=min(i,k);j++){
            if(j==0||j==i){
                C[i][j]=1;  
            }else{
                C[i][j]=C[i-1][j-1]+C[i-1][j]; 
            }
        } 
    }
    return C[n][k]; 
} 

//vector<vector<ll>> adj(N); 
ll dp[3001][3001];
ll solve(ll x,ll y,ll ar[]){
    if(x>y){
        return 0;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    ll ans=max(ar[x]+min(solve(x+2,y,ar),solve(x+1,y-1,ar)),ar[y]+min(solve(x+1,y-1,ar),solve(x,y-2,ar)));
    return dp[x][y]=ans;
}

int main(){
    sexy;
    ll T,x,y,z,p,q,r;
    cin>>x;
    ll ar[x+1];
    r=0;
    forz(i,x){
        cin>>ar[i+1];
        r=r+ar[i+1];
    }
    memset(dp,-1,sizeof(dp));
    y=solve(1,x,ar);
    r=r-y;
    p1((y-r));
    return 0;
}