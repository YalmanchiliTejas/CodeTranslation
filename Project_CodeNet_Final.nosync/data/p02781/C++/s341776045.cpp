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

ll dp[105][2][4];

int main2() {
  string S; cin >> S;
  int M = S.size();
  int K; cin >> K;

  CLR(dp, 0);
  dp[0][0][0] = 1;
  REP(i, M) {
    REP(f, 2) {
      REP(k, K+1) {
        // cout << i << " " << f << " " << k << " -> " << dp[i][f][k] << endl;
        REP(d, 10) {
          int nf = f || (S[i]-'0' > d);
          int nk = k + (!!d);
          if ((f || S[i]-'0' >= d) && nk <= K) {
            dp[i+1][nf][nk] += dp[i][f][k];
          }
        }
      }
    }
  }
  ll ans = dp[M][0][K] + dp[M][1][K];
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