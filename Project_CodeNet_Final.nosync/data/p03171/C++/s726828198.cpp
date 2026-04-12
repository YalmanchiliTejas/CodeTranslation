#include<bits/stdc++.h>
#include<string>
#include<map>
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define vii         vector<pair<ll,ll> >
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define rep1(i,a,b) for(ll i=a;i<= b;i++)
#define PI          3.14159
#define MAX         100000001
#define fast_io      ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
#define scan(var)    scanf("%lld",&var)
#define print(var)   printf("%lld\n", var);
#define BLOCK 317
#define double       long double
#define mod          998244353
using namespace std;
ll dp[3001][3001];
ll arr[3001];
ll solvedp(ll start,ll end)
{
  if(start == end)
  {
    return arr[start];
  }
  if(dp[start][end] != -1)
  {
    return dp[start][end];
  }
  ll ans = LLONG_MIN;
  ans = max(ans,max(arr[start] - solvedp(start + 1,end),arr[end] - solvedp(start,end - 1)));
  dp[start][end] = ans;
  return ans;
}
int main()
{
  fast_io
  ll n;
  cin >> n;
  rep(i,0,n)
  {
    cin >> arr[i];
  }
  memset(dp,-1,sizeof(dp));
  cout << solvedp(0,n - 1);
  return 0;
}

