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

const int MAX_N = 112345;
ll s[MAX_N];

int main2() {
  int N = nextInt();
  REP(i, N) s[i] = nextInt();
  ll ans = 0;
  for (int d = 1; d <= N-1; d++) {
    ll score = 0;
    set<int> vis;
    bool end = false;
    for (int k = 1; ; k++) {
      int x = k * d;
      int y = N-1 - k * d;
      if (vis.count(x) > 0) end = true; else vis.insert(x);
      if (vis.count(y) > 0) end = true; else vis.insert(y);
      int A = N-1-k*d;
      int B = A - d;
      if (!(1 <= A && A <= N-1 &&
            1 <= B && B <= N-1 &&
            B < A)) end = true;
      if (end) break;
      score += s[x];
      score += s[y];
      chmax(ans, score);
    }
  }

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