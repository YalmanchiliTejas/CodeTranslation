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
int dp[3001][3001][2];
int a[3001];
int n;
int ans(int l,int r,int p)
{
    int &res=dp[l][r][p];
    if(res!=-1)
        return dp[l][r][p];
    if(l==r)
    {
        if(p==0)
        {
            return res=a[l];
        }
        else
            return res=-a[l];
    }
    if(p==0)
    {
        res=max(ans(l+1,r,!p)+a[l],ans(l,r-1,!p)+a[r]);
    }
    else
        res=min(ans(l+1,r,!p)-a[l],ans(l,r-1,!p)-a[r]);
    return res;

}
int32_t main()
{
    IOS
    
  
  
  cin>>n;

  for(int i=0;i<n;++i)
    cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<-ans(0,n-1,1);


}

