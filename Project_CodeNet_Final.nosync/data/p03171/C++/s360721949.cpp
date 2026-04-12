#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define FS              ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll              long long int
#define ld              long double
#define pb              push_back
#define bp              __builtin_popcount
#define sz              size()
#define ff              first
#define ss              second
#define vll             vector<ll>
#define vbool           vector<bool>
#define vpll            vector<pair<ll,ll>>
#define pll             pair<ll,ll>
#define vllv            vector<vector<ll>>
#define setpri(x)       cout<<setprecision(x)<<fixed;
#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define yesr {cout<<"YES"<<endl;return;}
#define nor {cout<<"NO"<<endl;return;}
// getline (std::cin,name);
ll MOD=1e9+7;
ll ceil1(ll n,ll x){return (n-1)/x+(n>0);}

ll gcd(ll a,ll b){return __gcd(a,b);}
ll lcm(ll a,ll b){return (max(a,b)/gcd(a,b))*min(a,b);}

ll pow1(ll n,ll m ,ll mod=MOD );
ll pow2(ll n,ll k);

ll modinv(ll n,ll mod){  return pow1(n,mod-2,mod);}

bool func(pair<ll,ll> &a,pair<ll,ll> &b ){
        if(a.ff != b.ff)return a.ff < b.ff;
        return a.ss > b.ss;
}
ll const N=(ll)5e3+11;
ll const LG=(ll)log2(N)+1;
ll X=0,Y=0;
ll dp[N][N][2];
ll sol(vll &a,ll i,ll j,ll fl){
        if(j<i)return 0;

        ll &ans=dp[i][j][fl];
        if(ans!=-1)return ans;

        if(!fl)
                ans=max(sol(a,i+1,j,!fl)+a[i],sol(a,i,j-1,!fl)+a[j]);
        else
                ans=min(sol(a,i+1,j,!fl)-a[i],sol(a,i,j-1,!fl)-a[j]);
        return ans;

}
void solve(){
        ll i,j,k,l,n,m,x,y,z,r;

        cin>>n;
        vll a(n+2);
        for(i=1;i<=n;i++){
                cin>>a[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<sol(a,1,n,0);
        // cout<<dp[1][n][0]<<endl;



}   
int main(){
        FS;
       // #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        //#endif
        ll i,j,k,n,m,x,y,z,q;
        q=1;
        // cin>>q;
        while(q--){
                solve();
        }
        return 0;
}


ll pow1(ll n,ll m,ll mod){
        if(m==0)return 1;

        if(m%2==0)return pow1((n*n)%mod,m/2,mod);

        return (pow1((n*n)%mod,m/2,mod)*n)%mod;
}

ll pow2(ll n,ll k){
        ll ans=1;
        while(k>0){
                if(k%2==1)ans=ans*n;
                n=n*n;
                k/=2;
        }
        return ans;
}
