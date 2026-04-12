#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}

ll const mod =1e9+7;
int main() {
  int n;
  cin >> n;
  string s;
  cin >>s;
  map<char,int> c0,c1;
  for (auto i:s) c0[i]++;
  rep(i,n-1) {
    cin >> s;
    c1.clear();
    for (auto i:s) c1[i]++;
    for (auto i:"abcdefghijklmnopqrstuvwxyz") {
      chmin(c0[i],c1[i]);
    }
  }
  for (auto itr=c0.begin();itr!=c0.end();itr++) {
    cout << string(itr->second,itr->first);
  }
  cout << endl;
}