#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define inf LLONG_MAX
#define bp __builtin_popcountll
#define pb push_back
#define ff first
#define ss second
#define P pair<ll,ll>
#define N 100001
#define all(a) a.begin(),a.end()
#define LG 20
#define int ll
#define nl '\n'
#define sp " "
#define vi vector<int>
#define f(n) for(int i=0;i<n;i++)
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define ps(x,y) fixed<<setprecision(y)<<x
#define F(i,a,b) for(int i = a ; i < b ; i++)
#define print_vector(v) cout<< #v << " " ; for(auto j:v) cout<<j<<sp; cout<<nl;
#define deb(x) cout<< #x << " " << x << endl;


// vector<vector<int>> dp(100002, vector<int>(6,-1));
int dp[100002][6];


int power(int x, int y){
    if(y==0) return 1;
    int temp = power(x,y/2);

    int curr = (temp*temp)%mod;
    if(y%2) return (curr*x)%mod;
    else return curr;
}



// void dfs(int curr){

// }



void solve(){
    int n;
    cin>>n;
    vi v(n);
    f(n) cin>>v[i];
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum+=v[i];
        sum = sum%mod;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        sum-=(v[i]);
        if(sum<0) sum+=mod;
        ans+=((sum%mod)*(v[i]%mod));
        ans = ans%mod;
    }

    cout<<ans<<nl;
}

signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast;
    // int t;
    // cin>>t; 
    // while(t--){
        solve();
    // }
}