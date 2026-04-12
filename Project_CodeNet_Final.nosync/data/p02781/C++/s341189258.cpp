#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#pragma GCC optimize ("-O3")
#define mod2 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector <vector <int>>
#define v4096 vector <vector <lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli,lli>
#define m32 map<int,int>
#define m64it map<lli,lli>::iterator
#define m32it map<int,int>::iterator
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ist insert
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define p_q priority_queue 
#define min_p_q priority_queue <int,vt <int>,greater <int>>
using namespace std;
using namespace __gnu_pbds; 
template <typename T> 
void DEBUG_ARR(vt<T> a,char c)
{
	f(i,0,a.size())cout<<a[i]<<c;
	cout<<"\n";
}

lli tmod(lli x,lli m){return (x%m+m)%m;}//USE AT YOUR OWN RISK
lli power(lli x, lli y) 
{
    lli res = 1;  
   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x)%mod; 
        y = y>>1; 
        x = (x*x)%mod;  
    }
    if(res<0)
       res+=mod; 
    return res; 
}
string n;
lli k;
lli dp[105][5][2];
lli solve(int pos,int remain,int tight){
    if(pos==n.size()){
        if(remain==0)
        return dp[pos][remain][tight]=1;
        else return dp[pos][remain][tight]=0;
    }
    if(dp[pos][remain][tight]==-1){
        if(tight){
            if(remain==0)return dp[pos][remain][tight]=1;
            if(n[pos]=='0')
            dp[pos][remain][tight]=solve(pos+1,remain,tight);
            else dp[pos][remain][tight]=solve(pos+1,remain,0)+(n[pos]-'0'-1)*(n[pos]-'0'-1>0)*solve(pos+1,remain-1,0)+solve(pos+1,remain-1,1);
        }
        else{
            if(remain==0)return dp[pos][remain][tight]=1;
            dp[pos][remain][tight]=solve(pos+1,remain,tight)+9*solve(pos+1,remain-1,tight);
        }
    }
    return dp[pos][remain][tight];
}
int main() 
{ 
    fastio;
    memset(dp,-1,sizeof dp);
    cin>>n>>k;
    cout<<solve(0,k,1)<<"\n";
    return 0; 	
}
