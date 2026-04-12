// Author: Vinay Khilwani
// Language: C++

// @vok8: Codeforces, AtCoder, LeetCode, HackerEarth, TopCoder, Google, FB, CSES, Spoj, GitHub
// @vok_8: CodeChef, GFG
// @vok8_khilwani: HackerRank

// Never Stop Trying.
// Trying to be Better than Myself.

// while(true)
// {
//     if(AC)
//     {
//         break;
//     }
//     else if(Contest Over)
//     {
//         Try.
//         Check out Editorial.
//         Understand.
//         Find out your Mistake.
//         Learn the topic (if new).
//         Solve Problems on that topic (if new).
//         Upsolve that problem.
//         break;
//     }
//     else
//     {
//         Try.
//         Use Pen-Paper.
//         Find errors, edge cases, etc.
//         continue;
//     }
// }

// Optimizations
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#pragma GCC optimize("Os")

// Libraries
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;

// Debugging
#define dbg(a) cerr<<a<<"\n";
#define debug_a(a) for(auto x:a) {cerr<<x<<" ";} cerr<<"\n";
#define debug_b(a) for(auto x:a) {cerr<<"["<<x.first<<", "<<x.second<<"]"<<"\n";} cerr<<"\n";
#define debug_c(a) for(auto x:a) {debug_a(x)} cerr<<"\n";
#define debug_d(a) for(auto x:a) {debug_b(x)} cerr<<"\n";
#define debug_e(a) cerr<<"["<<a.first<<", "<<a.second<<"]"<<"\n";

// Defines
#define fast ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define loop(i,a,n) for(int i=a; i<n; i++)
#define rloop(i,a,n) for(int i=a; i>=n; i--)
#define fr(i,a,n,b) for(int i=a; i<n; i+=b)
#define rfr(i,a,n,b) for(int i=a; i>=n; i-=b)
#define IN cin>>
#define OUT cout<<
#define nl "\n"
#define sz(a) int(a.size())
#define all(a) (a).begin(),(a).end()
#define each(a,b) for(auto &a:b)
#define pb push_back
#define set_bits(a) __builtin_popcountll(a)
#define ar array
#define write(a) for(auto x:a) {OUT x<<" ";} OUT nl;
#define read(a) for(auto &x:a) {IN x;}
// #define oset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vi=vector<int>;
const ll mod=(ll)(1e9)+7LL;
const ll M=998244353LL;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const ld pi=acos(-1);

// General Functions
ll gcd(ll a, ll b)
{
    return (b?gcd(b,a%b):a);
}
ll P(ll B, ll power, ll modulo) //Fast Power
{
    ll ans=1LL;
    while(power>0LL)
    {
        if(power%2LL==1LL)
        {
            ans=(ans*B)%modulo;
        }
        B=(B*B)%modulo;
        power/=2LL;
    }
    return ans;
}
bool isPrime(ll n)
{
    if(n<=1LL)
    {
        return false;
    }
    if(n<=3LL)
    {
        return true;
    }
    if(n%2==0LL || n%3==0LL)
    {
        return false;
    }
    for(ll i=5LL; (i*i)<=n; i+=6LL)
    {
        if(n%i==0LL || n%(i+2LL)==0LL)
        {
            return false;
        }
    }
    return true;
}
void vok()
{
    fast
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif
}

// Global Variables
const int mxN=int(1e5)+100;

// Solver Function(s) 
void solve()
{
    ll n,x,m;
    IN n>>x>>m;
    vll terms;
    map<ll,bool> vis;
    while(!vis[x])
    {
        vis[x]=true;
        terms.pb(x);
        x=x*x;
        x%=m;
    }
    vll non_repeat;
    vll repeat;
    bool nr=true;
    each(xx,terms)
    {
        if(xx==x)
        {
            nr=false;
        }
        if(nr)
        {
            non_repeat.pb(xx);
        }
        else
        {
            repeat.pb(xx);
        }
    }
    vll prenr(sz(non_repeat)+1,0);
    vll prer(sz(repeat)+1,0);
    loop(i,1,sz(non_repeat)+1)
    {
        prenr[i]=prenr[i-1]+non_repeat[i-1];
    }
    loop(i,1,sz(repeat)+1)
    {
        prer[i]=prer[i-1]+repeat[i-1];
    }
    if(n<=sz(non_repeat))
    {
        OUT prenr[n]<<nl;
        return;
    }
    n-=sz(non_repeat);
    ll ans=prenr.back();
    ll times=n/sz(repeat);
    ll mid=n%sz(repeat);
    ans+=(times*prer.back());
    ans+=prer[mid];
    OUT ans<<nl;
}

// Main Function
int main()
{
    vok();
    int t=1;
    // IN t;
    while(t--)
    {
        solve();
    }
    return 0;
}