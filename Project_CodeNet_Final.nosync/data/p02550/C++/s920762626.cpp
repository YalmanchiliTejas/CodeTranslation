#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <sstream>
#include <string>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=100001;
bool vis[N];
vector <int> adj[N];
ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a); } 
ll lcm(ll a, ll b){return a*b/gcd(a, b);}
// ll binaryNum[64];
// void decToBinary(ll n, ll k) 
// { 
//     // binaryNum[64]={0};
//     rep(i,64){
//         binaryNum[i]=0;
//     }
//     int i = 0; 
//     while (n > 0) { 
//         binaryNum[i] = n % k; 
//         n = n / k; 
//         i++; 
//     } 
// }
// ll dp[2001][2001]; 
// ll countPartitions(ll n, ll k) 
// {   
//     if (n < k) 
//         return 0;
//     if (n < 2 * k) 
//         return 1; 
//     if (dp[n][k] >= 0) 
//         return dp[n][k]; 
//     ll answer = 1; 
//     for (int i = k; i < n; i++) 
//         answer = answer + countPartitions(n - i, k); 
//     dp[n][k] = answer%mod; 
//     return answer%mod; 
// } 
int M = LONG_MAX;

void solve(){
    ll n,x,m;
    cin>>n>>x>>m;
    vl a;
    a.pb(x);
    set<ll> st;
    st.insert(x);
    int flag=0;
    ll curr=x;
    ll ind=0;
    while(!flag){
        curr = (curr*curr)%m;
        // if(curr>=10000){
        //     cout<<curr<<'\n';
        // }
        if(st.find(curr) != st.end()){
            flag=1;
            break;
        }
        else{
            // ind++;
            a.pb(curr);
            st.insert(curr);
        }
    }
    // cout<<ind<<'\n';
    rep(i,a.size()){
        if(a[i]==curr){
            ind=i;
            break;
        }
    }
    ll tot = a.size();
    ll count = (n-ind)/(tot-ind);
    ll rem = (n-ind)%(tot-ind);
    // cout<<count<<'\n';
    // cout<<rem<<'\n';
    ll ans = 0;
    rep(i,ind){
        ans += a[i];
    }
    loop(i,ind,a.size()-1){
        ans += count*a[i];
    }
    loop(i,ind,ind + rem-1){
        ans += a[i];
    }
    cout<<ans;



}


int main()
{

    // cout<<1<<endl;
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    // cin>>T;
    int t=0;
    while(t++<T)
    {
        // cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}