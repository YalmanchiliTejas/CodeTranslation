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
int dp[100001][101][2];
int d;
string s;
int solve(int pos,int di,int f,int sum)
{
    if(di>d)
        return 0;
    if(pos==s.length())
    {
        //cout<<sum<<endl;
        if(di==0)
        return 1;
    else
        return 0;
    }
  //  cout<<pos<<" "<<di<<" "<<f<<" "<<sum<<endl;
    int &res=dp[pos][di][f];
    if(res!=-1)
        return dp[pos][di][f];
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
        
        
                res+=solve(pos+1,(sum+x)%d,k,sum+x);
                res=res%mod;
        
        
    }

    return res%mod;
}
int32_t main()
{
    IOS
     
    
    
    cin>>s;
    
    cin>>d;
    memset(dp,-1,sizeof(dp));
    int x=solve(0,0,0,0);
    int n=s.length();
    cout<<(x-1+mod)%mod<<endl;

}

