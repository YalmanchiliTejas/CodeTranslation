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

int main(void){
  int N;cin >> N;
  int a[N];
  REP(i,N) cin >> a[i];
  ll dp[N+1][N+1] = {0};
  for(int section=1; section<=N;section++){
    int isfirst = -1;
    if(section%2) isfirst=1;
    REP(l,N+1-section){
      int r = l+section;
      ll ret1 = dp[l+1][r] + isfirst*a[l];
      ll ret2 = dp[l][r-1] + isfirst*a[r-1];
      ret1*=isfirst;
      ret2*=isfirst;
      dp[l][r] = max(ret1,ret2);
      dp[l][r]*=isfirst;
    }
  }
  ll ans = dp[0][N];
  if(N%2==0)ans*=-1;
  cout << ans << endl;
  return 0;
}
