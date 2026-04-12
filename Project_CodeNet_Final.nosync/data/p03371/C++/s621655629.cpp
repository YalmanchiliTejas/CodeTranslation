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

int main2() {
  ll A = nextInt();
  ll B = nextInt();
  ll C = nextInt();
  ll X = nextInt() * 2;
  ll Y = nextInt() * 2;

  ll ans = 1LL << 61;
  for (int c = 0; c <= max(X, Y); c++) {
    ll am = C * c;
    ll AA = max(0LL, X - c);
    ll BB = max(0LL, Y - c);
    am += (AA+1)/2 * A;
    am += (BB+1)/2 * B;
    chmin(ans, am);
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