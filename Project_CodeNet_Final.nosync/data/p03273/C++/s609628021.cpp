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


int main2() {
  int H, W; cin >> H >> W;
  vector<string> s(H);
  REP(i, H) cin >> s[i];

  vector<int> existH(H);
  vector<int> existW(W);
  REP(i, H) REP(j, W) if (s[i][j]=='#') {
    existH[i] = 1;
    existW[j] = 1;
  }
  REP(i, H) {
    string line;
    REP(j, W) {
      if (existH[i] && existW[j]) {
        line += s[i][j];
      }
    }
    if (line.size() > 0) cout << line << endl;
  }
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}