#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0,i##_max=(N);i<i##_max;++i)
#define repp(i,l,r) for(int i=(l),i##_max=(r);i<i##_max;++i)
#define per(i,N) for(int i=(N)-1;i>=0;--i)
#define perr(i,l,r) for(int i=r-1,i##_min(l);i>=i##_min;--i)
#define all(arr) (arr).begin(), (arr).end()
#define SP << " " <<
#define SPF << " "
#define SPEEDUP cin.tie(0);ios::sync_with_stdio(false);
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

inline void YesNo(bool b){ cout << (b?"Yes" : "No") << endl;}
inline void YESNO(bool b){ cout << (b?"YES" : "NO") << endl;}
inline void Yay(bool b){ cout << (b?"Yay!" : ":(") << endl;}

ll conv(int n, int k){
  if(n<k) return 0;
  if(k==0) return 1;
  if(k==1) return n;
  if(k==2) return n*(n-1)/2;
  if(k==3) return n*(n-1)*(n-2)/(3*2);
  else return 0;
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  string S;cin >> S;
  int N = S.length();
  int K;cin >> K;
  int num = K;
  ll dp[N+1][2][K+1];
  rep(i,N+1) rep(j,2) rep(k,K+1) dp[i][j][k] = 0;
  dp[0][1][K] = 1;
  rep(i,N){
    rep(k,K+1) dp[i+1][0][k] =  dp[i][0][k];
    if(S[i] == '0') rep(j,2)rep(k,K+1) dp[i+1][j][k] =  dp[i][j][k];
    else{
      rep(k,K){
        dp[i+1][1][k] = dp[i][1][k+1];
        dp[i+1][0][0] += (S[i] - '1')*dp[i][1][k+1] * pow(9,k) * conv(N-i-1,k)
          + dp[i][1][k+1] * pow(9,k+1) * conv(N-i-1,k+1);
      }
      if(dp[i+1][1][0] == 1)++dp[i+1][0][0];
    }
  }
  cout << dp[N][0][0] << endl;
  return 0;
}
