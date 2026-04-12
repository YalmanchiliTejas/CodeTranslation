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

int main()                  
{
    int n;
    
    scn(n);
    
    ll sum=0;
    
    rep(i,0,n)
    {
        lscn(a[i]);
        
        sum+=a[i];  dp[i][i]=a[i];
    }
    
    rep(i,0,n-1)
    dp[i][i+1]=max(a[i],a[i+1]);
    
    for(int len=3;len<=n;len++)
    {
        for(int i=0;i+len-1<n;i++)
        {
            int j=i+len-1;
            
            ll x=a[i]+min(dp[i+1][j-1],dp[i+2][j]);
            
            ll y=a[j]+min(dp[i+1][j-1],dp[i][j-2]);
            
            dp[i][j]=max(x,y);
        }
    }
    
    ll player_1,player_2;
    
    player_1=dp[0][n-1];
    
    player_2=sum-player_1;
    
    ll ans=player_1-player_2;
    
    printf("%lld",ans);
} 
