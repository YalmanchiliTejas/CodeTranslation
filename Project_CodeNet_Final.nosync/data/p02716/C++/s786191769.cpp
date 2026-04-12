#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}


int nextInt() { int x; scanf("%d", &x); return x;}
ll nextLong() { ll x; scanf("%lld", &x); return x;}


const int MAX_N = 212345;
const ll INF = 1LL << 61;
ll dp[MAX_N][3];

int main2() {
  int N = nextInt();
  vector<ll> A(N);
  REP(i, N) A[i] = nextLong();

  REP(i, MAX_N) REP(j, 3) dp[i][j] = -INF;

  const int O = 2;
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    chmax(dp[i+O][0], dp[i-2+O][0] + A[i]);
    chmax(dp[i+O][1], dp[i-2+O][1] + A[i]);
    chmax(dp[i+O][2], dp[i-2+O][2] + A[i]);
    if (i-3+O >= 0) {
      chmax(dp[i+O][1], dp[i-3+O][0] + A[i]);
      chmax(dp[i+O][2], dp[i-3+O][1] + A[i]);
    }
    if (i-4+O >= 0) {
      chmax(dp[i+O][2], dp[i-4+O][0] + A[i]);
    }
  }

  // REP(k, 3) {
  //   REP(i, N+3) cout << dp[i][k] << " ";
  //   cout << endl;
  // }

  if (N % 2 == 1) {
    ll ans = max({
      dp[O+N-3][0],
      dp[O+N-2][1],
      dp[O+N-1][2],
    });
    cout << ans << endl;
  } else {
    ll ans = max({
      dp[O+N-2][0],
      dp[O+N-1][1],
    });
    cout << ans << endl;

  }

  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}