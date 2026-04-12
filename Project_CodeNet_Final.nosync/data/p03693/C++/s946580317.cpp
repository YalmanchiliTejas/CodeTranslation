#include <map>
#include <algorithm>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define DEBUG(X) cerr<<"  "<<#X<<" = "<<X<<endl;
#define DUMP(A, n) for (auto x=begin(A); x!=begin(A)+n;x++){cout <<*x<< ' ';} cout<<endl;
#define DUMPP(A, n, m) for (auto x=begin(A); x != begin(A)+n;x++) {for (auto y=begin(*x); y != begin(*x)+m;)cout <<*y++<< ' '; cout<<endl;};
#define DUMPM(M) for (auto itr=mp.begin(); itr!=mp.end(); itr++) {cout<<itr->first<<" -> "<<itr->second<<endl;}
#define FOR(i,x,y) for(int i=(x);i<(int)(y);i++)
#define FORP(i,x,y) for(int i=(x);i<=(int)(y);i++)
#define REP(i,y) for(int i=0;i<(int)(y);i++)
#define REPP(i,y) for(int i=1;i<=(int)(y);i++)
#define RREP(i,n) for(int i=(int)(n)-1;i>=0;i--)
int r,g,b;
int main() {
  cin >>r>>g>>b;
  int a = r*100 + g*10 + b;
  cout << (a%4==0 ? "YES" : "NO") << endl;
}
