/*-------------------------------"ANJAN AGARWALA"-----------------------------

         _/_/_/_/    _/_/    _/   _/_/_/_/   _/_/_/_/    _/_/    _/   
        _/    _/    _/ _/   _/         _/   _/    _/    _/ _/   _/        
       _/_/_/_/    _/   _/ _/         _/   _/_/_/_/    _/  _/  _/         
      _/    _/    _/    _/_/   _/    _/   _/    _/    _/    _/_/  
     _/    _/    _/      _/   _/_/_/_/   _/    _/    _/      _/   

-------------------------------------@anjn98---------------------------------*/

//#define opti
#ifdef opti
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long int LL;
typedef unsigned long long int ull;
ll power(ll x,ll y,ll p){ll r=1; x=x%p; while(y){ if(y&1) r= r*x%p; y=y>>1; x=x*x%p; } return r; }
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;*/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int csrand(int l=0, int r=1e9){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

#define IO              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FILEIO          freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define all(v)          v.begin(),v.end()
#define PR(a)           cout<<"("<<a<<")";
#define ED              cout<<'\n';
#define endl            '\n'
#define loop(j,a,n)     for(int j=a;j<=n;j++)
#define loop1(j,a,n)    for(int j=a;j>=n;j--)
#define fr1(j,n)        for(int j=0;j<n;j++)
#define fr(n)           for(int i=0;i<n;i++)
#define trav(x,s)       for(auto x:s)
#define SC(n)           scanf("%d",&n)
#define PB              push_back
#define MP              make_pair
#define pii             pair<int,int>
#define pll             pair<long long int,long long int>
#define F               first
#define S               second 
#define binf            2000000000000000001
#define mod             1000000007


const int N=1e4+99;

ll dp[N][105][2],d,len; string s;

ll solve(int i,int sum,int tk)
{
    if(i==len) return sum%d==0; 

    if(dp[i][sum][tk]!=-1) return dp[i][sum][tk];
    ll ans=0; int k=s[i]-'0';

    for(int j=0;j<k;j++)
        ans=(ans+solve(i+1,(sum+j)%d,1))%mod;
    ans=(ans+solve(i+1,(sum+k)%d,tk))%mod;

    for(int j=k+1;j<=9 && tk==1;j++)
        ans=(ans+solve(i+1,(sum+j)%d,tk))%mod;

    return dp[i][sum][tk]=ans;
}
int main() 
{
    IO
    memset(dp,-1,sizeof(dp));

    cin>>s>>d;
    len=s.length();

    ll ans=(solve(0,0,0)-1+mod)%mod;

    cout<<ans<<endl;
}




 