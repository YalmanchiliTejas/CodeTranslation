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

void naive(ll N, ll K) {
  ll res = 0;
  for (int a = 1; a <= N; a++) {
    for (int b = 1; b <= N; b++) {
      if (a % b >= K) { 
        res++;
      }
    }
  }
  cout << res << endl;
}

int main2() {
  ll N, K; cin >> N >> K;
  // if (N <= 1000) {
    // naive(N, K);
    // return 0;
  // }

  if (K == 0) {
    cout << N * N << endl;
    return 0;
  }
  ll ans = 0;
  for (ll b = K+1; b <= N; b++) {
    ans += (N+1)-(((N+1)/b*K) + min(K,(N+1)%b));
    // cout << b << " " << ans << endl;
  }
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
