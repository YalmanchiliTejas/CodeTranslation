#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define rep(i,n) for(int i=0;i<(int)n;++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define debug(x) cout << #x << "=" << (x) << endl;
const ll MOD=1e9+7;
#define itn int
#define tin int
#define nit int
#define tni int
#define nti int
#define fro for
#define ofr for
#define ccin cin

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> void fail(T v){cout << v << endl;exit(0);}
//template end

void solve(){
  ll K,A,B;
  cin>>K>>A>>B;
  K-=A;
  if(K<=0)fail(1);
  if(A<=B)fail(-1);
  cout<<1+(K+A-B-1)/(A-B)*2<<endl;
  
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}