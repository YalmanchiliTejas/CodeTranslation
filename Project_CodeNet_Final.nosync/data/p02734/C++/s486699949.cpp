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

const ll MOD = 998244353;
const int MAX_N = 3005;
const int MAX_S = 3005;

ll dp[MAX_N][MAX_S];
int A[MAX_N];

int main2() {
  CLR(dp, 0);
  int N = nextInt();
  int S = nextInt();
  REP(i, N) A[i] = nextInt();

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    dp[i][0] += 1;
    for (int s = 0; s <= S; s++) {
      (dp[i+1][s] += dp[i][s]) %= MOD;
      if (s + A[i] <= S) {
        (dp[i+1][s + A[i]] += dp[i][s]) %= MOD;
      }
    }
    ans += dp[i+1][S];
    ans %= MOD;
  }
  ans %= MOD;
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