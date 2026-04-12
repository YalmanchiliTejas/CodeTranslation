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

string t[100];
bool ap1[100];
bool ap2[100];

int main2() {
  int H = nextInt();
  int W = nextInt();

  REP(i, H) cin >> t[i];

  CLR(ap1, 0);
  CLR(ap2, 0);

  REP(i, H) {
    REP(j, W) {
      if (t[i][j] == '#') {
        ap1[i] = true;
        ap2[j] = true;
      }
    }
  }

  REP(i, H) {
    int c = 0;
    REP(j, W) {
      if (ap1[i] && ap2[j]) { cout << t[i][j]; c++; }
    }
    if (c > 0) cout << endl;
  }
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
