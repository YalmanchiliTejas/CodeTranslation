#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 100000
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int mod(int x,int y)
{
  int s;
  s = abs(x)/y;
  if(x<0)s--;
  return x-y*s;
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col;
ll ara[3005];
ll memo[2][3005][3005];
ll dp(int t,int i,int j)
{
  if(i == j)
  {
    if(t == 0)return ara[i];
    return -ara[i];
  }
  ll p1,p2;
  if(memo[t][i][j]!=-1)return memo[t][i][j];
  if(t == 0)
  {
    p1 = ara[i] + dp(1,i+1,j);
    p2 = ara[j] + dp(1,i,j-1);
    return memo[t][i][j] =max(p1,p2);
  }
  else
  {
    p1 = -ara[i] + dp(0,i+1,j);
    p2 = -ara[j] + dp(0,i,j-1);
    return memo[t][i][j] = min(p1,p2);
  }
}
void solve()
{
  scanf("%lld",&n);
  memset(memo,-1,sizeof memo);
  for(int w=0;w<n;w++)scanf("%lld",&ara[w]);
  ll ans = dp(0,0,n-1);
  cout << ans << endl;

}
void test()
{
  int t;
  //scanf("%d",&t);
  t = 1;
  for(int test=1;test<=t;test++)
  {
    solve();
  }
}
int main()
{
  test();
  return 0;
}
