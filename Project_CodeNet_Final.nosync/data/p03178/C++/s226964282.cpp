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

const ll MOD = (ll)(1e9 + 7);

ll dp[10000 + 10][105][2];

int main2() {
  string K; cin >> K;
  int D; cin >> D;
  int N = K.size();
  CLR(dp, 0);
  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int d = 0; d < D; d++) {
      for (int x = 0; x < 10; x++) {
        (dp[i+1][(d+x) % D][1] += dp[i][d][1]) %= MOD;
        if (K[i]-'0' > x) {
          (dp[i+1][(d+x) % D][1] += dp[i][d][0]) %= MOD;
        } else if(K[i]-'0' == x) {
          (dp[i+1][(d+x) % D][0] += dp[i][d][0]) %= MOD;
        }
      }
    }
  }
  ll ans = (dp[N][0][0] + dp[N][0][1]) % MOD;
  ans = (ans - 1 + MOD) % MOD;
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
