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

int main(void){
  SPEEDUP
  cout << setprecision(15);
  int N;cin >> N;
  vector<ll> v(N);
  vector<ll> w(N);
  rep(i,N)cin >> v[i];
  int s;
  ll sum;
  ll mini;
  ll ans = 0;

  sort(all(v));
  s = 0;
  rep(i,N){
    w[i] = v[s];
    if(s>N/2) s = N - s;
    else s = N - s - 1;
  }
  sum = 0;
  mini = MAX_LL;
  rep(i,N){
    sum += abs(w[(i+1)%N] - w[i]);
    mini = min(mini,abs(w[(i+1)%N] - w[i]) );
  }
  ans = max(ans,sum-mini);

  reverse(all(v));
  s = 0;
  rep(i,N){
    w[i] = v[s];
    if(s>N/2) s = N - s;
    else s = N - s - 1;
  }
  sum = 0;
  mini = MAX_LL;
  rep(i,N){
    sum += abs(w[(i+1)%N] - w[i]);
    mini = min(mini,abs(w[(i+1)%N] - w[i]) );
  }
  ans = max(ans,sum-mini);
  cout << ans << endl;
  return 0;
}
