// g++ -std=c++14

//Difficulty according to solve count during contest:
//A B C D H F E I G K L M N P S O Q R J U Z Y X T V W

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(c) (c.begin(),c.end())
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define inf 1000000000000000001

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

#define int ll

int n;
vector<int> a;
vector<vector<vector<int> > > dp;
int func(int i, int j, int turn){
  if(dp[i][j][turn] != INT_MIN)
    return dp[i][j][turn];
  if(i == j){
    if(turn == 0)
      return a[i];
    else
      return -a[i];
  }
  if(turn == 0)
    dp[i][j][turn] = max(a[i] + func(i + 1, j, 1), a[j] + func(i, j - 1, 1));
  else
    dp[i][j][turn] = min(-a[i] + func(i + 1, j, 0), -a[j] + func(i, j - 1, 0));
  return dp[i][j][turn];
}
int32_t main(){
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  dp.resize(n, vector<vector<int> > (n, vector<int>(2, INT_MIN)));
  int ans = func(0, n - 1, 0);
  cout << ans << endl;
}
