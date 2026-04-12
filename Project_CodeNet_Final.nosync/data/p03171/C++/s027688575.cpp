#include <bits/stdc++.h> 
using namespace std; 
#define flash ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define debug(x) cerr << " - " << #x << ": " << x << endl;
#define debugs(x, y) cerr << " - " << #x << ": " << x << " " << #y << ": " << y << endl;
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)x.size()
#define ll long long
#define INF 1000000000
#define pb push_back
struct greateri
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};
int x;
deque<ll>sol;
vector<int>gg;
ll dp[3001][3001];
bool flag[3001][3001];
ll solve(int x,int y)
{
  if(flag[x][y]!= 0)return dp[x][y];
  flag[x][y]=1;
  if(x==y){
    return dp[x][y]=gg[x];
  }
  return dp[x][y]=max(gg[x]-solve(x+1,y),gg[y]-solve(x,y-1));
}
int main()
{
  // flash;
  cin>>x;
  //memset(dp,-1,sizeof dp);
  for (int i = 0; i < x; ++i)
  {
    ll s;
    cin>> s;
    gg.pb(s);
  }
  cout<<solve(0,x-1);
  return 0;
}