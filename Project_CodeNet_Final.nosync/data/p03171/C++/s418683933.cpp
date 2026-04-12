#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define FAST()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define fill(a, i) memset(a, i, sizeof(a))
#define all(vec) vec.begin(),vec.end()
#define revall(vec) vec.rbegin(),vec.rend()
#define v vector
#define tlll tuple<ll, ll, ll>
#define pb push_back
#define fr(i, a, b) for (int i = a; i < b; ++i) 
const ll maxn=3e3+5;
ll dp[maxn][maxn];
void solve()
{
   ll n;
   cin>>n;
   ll arr[n+1];
   fr(i,0,n)cin>>arr[i+1];
   fr(i,1,n+1)
   dp[i][i]=arr[i];
   ll pref[n+1];
   pref[0]=0;
   fr(i,1,n+1)
   pref[i]=pref[i-1]+arr[i];
   for(int l=2;l<=n;++l)
   {
       for(int i=1;i+l-1<=n;++i)
       {
           ll a,b;
           a=arr[i]+pref[i+l-1]-pref[i]-dp[i+1][i+l-1];
           b=arr[i+l-1]+pref[i+l-2]-pref[i-1]-dp[i][i+l-2];
           dp[i][i+l-1]=max(a,b);
       }
   }
   cout<<dp[1][n]*2-pref[n];

}
int main()
{
    ll t=1;
    // cin>>t;
    while(t--)
    solve();
}