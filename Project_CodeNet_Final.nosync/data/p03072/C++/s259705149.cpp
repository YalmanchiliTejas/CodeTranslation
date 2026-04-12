#include <bits/stdc++.h>
using namespace std;
#define FOR(i, o, n) for (auto i = (o); (i) < (n); ++(i))
#define FOR1(i, n) FOR(i, 1, n+1)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (auto i = (n)-1; (i) >= 0; --i)
#define REPI(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define REPIR(itr, v) for (auto itr = v.rbegin(); itr != v.rend(); ++itr)
#define fi first
#define se second
#define ll long long
#define int long long
#define V2(name, h, w) vector<vector<int> > name((h), vector<int>(w));
#define myCeil(dividend, divisor) ceil((double)(dividend) / (double)(divisor))
#define myFloor(dividend, divisor) floor((double)(dividend) / (double)(divisor))
#define calcDigits(num) floor(log10(num))+1

#define dl(line) cerr << "RUN: until " << (line) << "th line." << endl;
#define dv(name, value) cerr << (name) << " is " << (value) << endl;
#define da(v)  cerr << "["; REPI(itr, v){cerr << *itr << (itr != --v.end() ? ", " : "");} cerr << "]" << endl;
#define dpa(v) cerr << "[ " << endl;REPI(itr, v) { cerr << "  [" << (*itr).first << ", " << (*itr).second << ']' << (itr != --v.end() ? "," : "") << endl; } cerr << "]" << endl;


void solve(long long N, std::vector<long long> H){
  int maxN = 0;
  int cnt = 0;
  REP(x, N) {
    if (maxN <= H.at(x)) {
      maxN = H.at(x);
      cnt++;
    }
  }
  cout << cnt << endl;
}

signed main(){
  long long N;
  scanf("%lld",&N);
  std::vector<long long> H(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&H[i]);
  }
  solve(N, std::move(H));
}
