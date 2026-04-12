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
const int N=1e5+4;

string s;

int d;

int dp[N][2][104];

void add_self(int &a,int b)
{
    a+=b;
    
    if(a>=mod)
    a-=mod;
}

int rec(int ind,int flag,int rem)
{
    if(ind==s.size())
    {
        return rem==0;
    }
    
    int &ans=dp[ind][flag][rem];
    
    if(ans!=-1)
    return ans;
    
    ans=0;
    
    int lim=9;
    
    if(flag==0)
    lim=s[ind]-'0';
    
    rep(i,0,lim+1)
    {
        int hf=flag,hrem=rem;
        
        if(i<lim)
        hf=1;
        
        hrem=(hrem+i)%d;
        
        ll here=rec(ind+1,hf,hrem);
        
        add_self(ans,here);
    }
    
    return ans;
}

int main()                  
{
    memset(dp,-1,sizeof(dp));
    
    cin>>s;
    
    scn(d);
    
    int ans=rec(0,0,0);
    
    ans--; //we have to count from 1 to given number, so subtract contribution of 0
    
    if(ans==-1)
    ans+=mod;
    
    printf("%d ",ans);
} 