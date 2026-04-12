#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll>   vl;
#define f(i,n)  for(i=0;i<n;i++)
#define f1(i,n)  for(i=1;i<n;i++)
#define fr(i,n) for(i=n-1;i>=0;i--)
#define em emplace_back
#define mp make_pair
#define in insert
#define fi first
#define sc second
#define b begin
#define e end
#define er erase
#define l length
#define c clear
#define si size
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
const double pi=3.141592653;
const ll infi=1000000001;
const ll MOD=1000000007;
const ll mod=998244353;
const string no="NO\n",yes="YES\n";

// ll gcd(ll a,ll b){
//     if(a==0)    return b;
//     gcd(b%a,a);
// }

// void dfs(vl v[],ll node,ll hai[]){
//     hai[node]=1;
//     for(auto i:v[node]){
//         if(hai[i]==0){
//             dfs(v,i,hai);
//         }
//     }
// }

// ll con(vl v[],ll hai[],ll sz){
//     ll count=0;
//     for(int i=1;i<sz;i++){
//         if(hai[i]==0){
//             count++;
//             dfs(v,i,hai);
//         }
//     }
    // return count;
// }

// void gcde(int a,int b,int *x,int *y){
//     if(a==0){
//         *x=0;
//         *y=1;
//         return;
//     }    
//     int x1,y1;
//     gcde(b%a,a,&x1,&y1);
    
//     *x=y1-(b/a)*x1;
//     *y=x1;
// }


// ll recur(vl v,ll in,ll m,ll n){
//     if(in==-1)  return 1000000000001;
//     ll d,e,c;
//     d=max(m/v[in],n*v[in]);
//     c=recur(v,in-1,m/v[in],n*v[in]);
//     e=recur(v,in-1,m,n);
//     return min(c,min(e,d));
// }

// ll bexpo(ll a,ll p){
//     ll x=1;
//     while(p){
//     if(p&1){
//         x=(x*a)%mod;
//     }
//     a=(a*a)%mod;
//     p>>=1;
//     }
//     return x;
// }
// ll fact[500001],invf[500001];
// int dx[8]{-1,0,0,1,-1,-1,1,1};
// int dy[8]{0,-1,1,0,-1,1,-1,1};
// ll dp[200001];


int main() {
    fastio
    int n;
    cin>>n;
    ll a[n],s=0,i,j;
    f(i,n){
        cin>>a[i];
        s+=a[i];
    }
    ll ans=0;
    f(i,n-1){
        s-=a[i];
        ans=(ans+(a[i]*(s%MOD))%MOD)%MOD;
    }
    cout<<ans;

	return 0;
}