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

bool f(vector<ll> &a) {
  int N = (int)a.size();
  if (*max_element(ALL(a)) < N)
    return false;
  REP(i, N) a[i]++;
  *max_element(ALL(a)) -= (N+1);
  return true;
}

void print(const vector<ll> &a) {
  int N = (int)a.size();
  cout << N << endl;
  REP(i, N) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int main2() {
  int N; cin >> N;
  vector<ll> a;
  REP(i, N) { ll x; cin >> x; a.push_back(x); }
  ll ans = 0;
  for (;;) {
    bool change = false;
    REP(i, N) {
      ll k = a[i] / N;
      if (k >= 1) {
        REP(j, N) {
          if (i == j) {
            a[j] -= k*N;
          } else {
            a[j] += k;
          }
        }
        ans += k;
        change = true;
      }
    }
    if (!change)
      break;
  }
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
