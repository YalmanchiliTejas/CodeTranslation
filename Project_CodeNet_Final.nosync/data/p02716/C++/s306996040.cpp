#include <bits/stdc++.h>
using namespace std;
//#include "testlib.h"
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define int long long
#define ll long long
#define M 1000000007
#define MM 998244353
#define inputarr(a,n) for(int i=0;i<n;++i) cin>>a[i]
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) m*(n/GCD(m,n))
#define mii  map<ll ,ll >
#define sz(a) (int)a.size()
#define msi  map<string,ll >
#define rep(a,b)    for(ll i=a;i<b;i++)
#define rep0(n)    for(ll i=0;i<n;i++)
#define repi(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define ppb pop_back
#define endl '\n'
#define asdf ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define r0 return 0;
#define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define inputoutput freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define Set(a, s) (a, s, sizeof (a))
#define FOR repi
#define vii vector<pii>
#define pii pair<int,int>
#define REVERSE(v) reverse(all(v))
#define trav(a, x) for(auto& a : x)
#define display(x) trav(a,x) cout<<a<<" ";cout<<endl
#define debug cerr<<"bhau"<<endl
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
template<typename T, typename U> static inline void amin(T &x, U y) 
{ 
    if (y < x) 
        x = y; 
}
template<typename T, typename U> static inline void amax(T &x, U y) 
{ 
    if (x < y) 
        x = y; 
}
 
ll max(ll a, ll b) { return (a > b)? a : b;}
int min(int a, int b) { return (a < b)? a : b;} 
int max(int a,int b,int c){
    return max(a,max(b,c));
}

int solve(){

    int n;cin>>n;
    int a[n];
    inputarr(a,n);
    int sum=0;
    rep0(n) sum+=a[i];
    if(n==2) return cout<<max(a[0],a[1]),0;
    // int dp[n+1][2];
    // memset(dp,0,sizeof(dp));
    if(n%2==0){
          int dp[n+1][2];
            // 0 -> only taking 1 diff 1-> now only can take atmost 1 "2" jump
            // memset(dp,0,sizeof(dp));
            rep0(n+1) repi(j,0,2) dp[i][j]=-1e15;
            dp[0][0]=a[0];

            rep(1,n){
                // repi(j,0,3) dp[i][j]=dp[i-1][j];
                if(i==1) amax(dp[i][0],a[i]);
                if(i-2>=0){
                    dp[i][0]=max(dp[i][0],dp[i-2][0]+a[i]);
                    dp[i][1]=max(dp[i][1],dp[i-2][1]+a[i]);
                    // dp[i][2]=max(dp[i][1],dp[i-2][2]+a[i]);
                    // if(i==6) trace(dp[i-2][2]+a[i]);
                }
                if(i-3>=0){
                    dp[i][1]=max(dp[i][1],dp[i-3][0]+a[i]);
                    // dp[i][2]=max(dp[i][2],dp[i-3][1]+a[i]);
                    // dp[i][2]=max(dp[i][1],dp[i-3][2]+a[i]);
                }
               
                dp[i][1]=max(dp[i][1],dp[i][0]);
                // dp[i][2]=max(dp[i][2],dp[i][1]);
                // trace(i,dp[i][0],dp[i][1],dp[i][2],a[i]);
            }
            // int ans=max(dp[n-1][0],max(dp[n-1][2],dp[n-1][1]));
             int ans=max(dp[n-1][1],dp[n-2][0]);
             amax(ans,dp[n-1][0]);
            // trace(ans);
           
            cout<<ans;return 0;
    }
    int dp[n+1][3];
    // 0 -> only taking 1 diff 1-> now only can take atmost 1 "2" jump
    // memset(dp,0,sizeof(dp));
    rep0(n+1) repi(j,0,3) dp[i][j]=-1e15;
    dp[0][0]=a[0];

    rep(1,n){
        // repi(j,0,3) dp[i][j]=dp[i-1][j];
        if(i==1) amax(dp[i][0],a[i]);
        if(i-2>=0){
            dp[i][0]=max(dp[i][0],dp[i-2][0]+a[i]);
            dp[i][1]=max(dp[i][1],dp[i-2][1]+a[i]);
            dp[i][2]=max(dp[i][1],dp[i-2][2]+a[i]);
            // if(i==6) trace(dp[i-2][2]+a[i]);
        }
        if(i-3>=0){
            dp[i][1]=max(dp[i][1],dp[i-3][0]+a[i]);
            dp[i][2]=max(dp[i][2],dp[i-3][1]+a[i]);
            // dp[i][2]=max(dp[i][1],dp[i-3][2]+a[i]);
        }
        if(i-4>=0){
            dp[i][2]=max(dp[i][2],dp[i-4][0]+a[i]);
        }
        dp[i][1]=max(dp[i][1],dp[i][0]);
        dp[i][2]=max(dp[i][2],dp[i][1]);
        // trace(i,dp[i][0],dp[i][1],dp[i][2],a[i]);
    }
    // int ans=max(dp[n-1][0],max(dp[n-1][2],dp[n-1][1]));
    int ans=max(dp[n-1][2],dp[n-2][1],dp[n-3][0]);
    // trace(ans);
    int s1=0;
    rep(2,n){
        s1+=a[i];
        i++;
    }
    ans=max(ans,s1);
    cout<<ans;
    // dp[1][0]=a[1];
    // dp[2][0]=max(a[2],a[0]+a[2]);
    // dp[2][
    return 0;
}
signed main(){
    asdf
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
