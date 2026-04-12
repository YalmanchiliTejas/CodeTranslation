#include <bits/stdc++.h>
using namespace std;
#define REP(i,N) for(int i=0;i<N;i++)
#define MAX_I INT_MAX //1e9
#define MIN_I INT_MIN //-1e9
#define MAX_UI UINT_MAX //1e9
#define MAX_LL LLONG_MAX //1e18
#define MIN_LL LLONG_MIN //-1e18
#define MAX_ULL ULLONG_MAX //1e19
  typedef long long ll;
  typedef pair<int,int> PII;
  typedef pair<char,char> PCC;
  typedef pair<ll,ll> PLL;
  typedef pair<char,int> PCI;
  typedef pair<int,char> PIC;
  typedef pair<ll,int> PLI;
  typedef pair<int,ll> PIL; 
  typedef pair<ll,char> PLC; 
  typedef pair<char,ll> PCL; 

ll dp[3001][3001];
bool visited[3001][3001] = {false};
vector<int> a;

ll dfs(int cur, int l, int r){
  if(visited[l][r]) return dp[l][r]; 
  if(l>r) return 0;
  int isfirst;
  if(cur%2==0) isfirst = 1;
  else isfirst = -1;
  ll ret1 = dfs(cur+1, l+1, r) + isfirst*a[l];
  ll ret2 = dfs(cur+1, l, r-1) + isfirst*a[r];
  ll ret = max(isfirst*ret1,isfirst*ret2);
  ret *= isfirst;
  visited[l][r] = true;
  return dp[l][r] = ret;
}

int main(void){
  int N;cin >> N;
  a.resize(N);
  REP(i,N) cin >> a[i];
  cout << dfs(0,0,N-1) << endl;
  return 0;
}
