#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 1000000007
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
ll mod(ll x,ll y)
{
  ll s;
  s = abs(x)/y;
  if(x<0)s--;
  return x-y*s;
}
ll dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
ll dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col;
char s[10005];
vector<ll> num;
ll memo[10006][2][104];
ll add(ll x,ll y)
{
  if(x+y < maxn)return x+y;
  return (x+y)%maxn;
}
ll dp(ll i,ll tight,ll sum)
{
  if(i >= num.size())
  {
    if(sum == 0)return 1;
    return 0;
  }
  if(memo[i][tight][sum]!=-1)return memo[i][tight][sum];
  ll lim = 9;
  if(tight == 1)lim = num[i];
  ll newT;
  ll ans = 0;
  for(ll w=0;w<=lim;w++)
  {
    if(w == num[i])newT = tight;
    else newT = 0;
    ans = add(ans,dp(i+1,newT,(sum + w)%n));
  }
  memo[i][tight][sum] = ans;
  return ans;

}
void solve()
{
  scanf("%s",s);
  scanf("%lld",&n);
  memset(memo,-1,sizeof memo);
  for(ll i=0;s[i];i++)num.pb(s[i]-48);
  ll ans = dp(0,1,0);
  if(ans == 0)cout<< maxn-1 << endl;
  else cout << ans-1 << endl;

}
void test()
{
  ll t;
  //scanf("%d",&t);
  t = 1;
  for(ll test=1;test<=t;test++)
  {
    solve();
  }
}
int main()
{
  test();
  return 0;
}
