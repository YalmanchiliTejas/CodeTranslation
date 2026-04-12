#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>bool chmin(T&a,const T&b){return a>b?(a=b,1):0;}
template<class T>bool chmax(T&a,const T&b){return a<b?(a=b,1):0;}


int main2() {
  int N; cin >> N;
  vector<ll> a(N);
  REP(i, N) cin >> a[i];
  ll ans = 0;
  for (;;) {
    auto p = max_element(ALL(a));
    if (*p < N) break;
    ll d = *p - (N-1);
    ll k = (d + N - 1) / N;
    ans += k;
    REP(i, N) a[i] += k;
    *p -= (N+1) * k;
  }
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws) main2();
  return 0;
}

