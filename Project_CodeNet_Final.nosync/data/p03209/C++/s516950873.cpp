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

ll x[55];
ll y[55];

ll f(int level, ll X) {
  if (level < 0) return 0;
  if (level == 0) {
    if (X == 1) return 1; else return 0;
  }

  if (X <= 1) return 0;
  else if (X <= 1 + x[level-1]) {
    return f(level - 1, X-1);
  }
  else if (X <= 2 + x[level-1]) {
    return 1 + f(level - 1, X-2);
  }
  else if (X <= 2+ 2*x[level-1]) {
    return 1 + y[level-1] + f(level-1, X-2-x[level-1]);
  }
  else return y[level];
}


int main2() {
  int N; cin >> N;
  ll X; cin >> X;

  x[0] = 1;
  y[0] = 1;
  REP(i, 50) x[i+1] = x[i] * 2 + 3;
  REP(i, 50) y[i+1] = y[i] * 2 + 1;

  ll ans = f(N, X);
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
