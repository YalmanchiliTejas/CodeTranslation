//Author:- S_Aditya

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long 
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
#define lpri(n) printf("%lld",n)
#define pri(n) printf("%d",n)
#define pln() printf("\n")
#define priln(n) printf("%d\n",n)
#define lpriln(n) printf("%lld\n",n)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define pb push_back     
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define inf INT_MAX
#define ninf INT_MIN
const ll mod=1e9+7;         
const int N=3e3+4;

ll a[N];

//dp[i][j] tells the maximum value first player can take,
//if we the range is i to j and first player starts the game

ll dp[N][N];

ll rec(int i,int j)
{
    if(i==j)
    return a[i];
    
    if(i>j)
    return 0;
    
    ll &here=dp[i][j];
    
    if(here!=-1)
    return here;
    
    here=0;
    
    ll v1=min(rec(i+2,j),rec(i+1,j-1))+a[i];
    
    ll v2=min(rec(i+1,j-1),rec(i,j-2))+a[j];
    
    here=max(v1,v2);
    
    return here;
}

int main()                  
{
    int n;
    
    scn(n);
    
    ll sum=0;
    
    rep(i,0,n)
    lscn(a[i]),sum+=a[i];
    
    memset(dp,-1,sizeof(dp));
    
    ll x=rec(0,n-1);
    
    ll ans=x-(sum-x);
    
    lpri(ans);
} 
