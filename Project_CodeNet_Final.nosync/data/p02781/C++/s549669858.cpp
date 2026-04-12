#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <iterator>
#include <functional>
#include <limits>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
typedef int64_t ll;
 
#define endl '\n'
#define int ll
ll mod=1e9+7;
ll mod1=1e9+5;
ll power(ll a,ll b)
{
    if(b==0) return 1;
    else if(b%2==0)
        return power((((a%mod)*(a%mod))%mod),b/2)%mod;
    else return ((a%mod)*(power((((a%mod)*(a%mod))%mod),b/2)%mod))%mod;
}
int dp[1001][6][7];
string s;
int k1;
 
int solve(int pos,int f,int num)
{
 
    
    if(pos==s.size())
    {
        
        if(num==k1)
            return 1;
        return 0;
    }
  
   int &res=dp[pos][f][num];
   if(res!=-1)
    return res;
    res=0;
    int fin;
    if(f==0)
    {
        fin=s[pos]-'0';
    }
    else
        fin=9;
   // cout<<fin<<endl;

    for(int x=0;x<=fin;++x)
    {
        int k=f;
        if(f==0 and x<fin)
            k=1;
        if(x==0)
        {
            res+=solve(pos+1,k,num);
        }
        else
        {
            res+=solve(pos+1,k,min(num+1,(ll)4));
        }
        
    }
 
    return res;
}


int32_t main()
{
    IOS
     
   
    

    cin>>s>>k1;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0);
    
 
}