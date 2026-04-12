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

ll dp[105][5][2];

int main2() {
  CLR(dp, 0);
  string N; cin >> N;
  const int M = N.size();
  int K = nextInt();

  dp[0][0][0] = 1;
  for (int i = 0; i < M; i++) {
    for (int k = 0; k <= K; k++) {
      for (int d = 0; d <= 9; d++) {
        if (N[i] > '0' + d) {
          if (d == 0) {
            dp[i+1][k][1] += dp[i][k][0];
            dp[i+1][k][1] += dp[i][k][1];
          } else {
            dp[i+1][k+1][1] += dp[i][k][0];
            dp[i+1][k+1][1] += dp[i][k][1];
          }
        } else if (N[i] == '0' + d) {
          if (d == 0) {
            dp[i+1][k][0] += dp[i][k][0];
            dp[i+1][k][1] += dp[i][k][1];
          } else {
            dp[i+1][k+1][0] += dp[i][k][0];
            dp[i+1][k+1][1] += dp[i][k][1];
          }
        } else if (N[i] < '0' + d) {
          if (d == 0) {
            dp[i+1][k][1] += dp[i][k][1];
          } else {
            dp[i+1][k+1][1] += dp[i][k][1];
          }
        }
      }
    }
  }
  ll ans = dp[M][K][0] + dp[M][K][1];
  cout << ans << endl;
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
