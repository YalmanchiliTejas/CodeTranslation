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

#define dl(line) cerr << "RUN: until " << (line) << "th line." << endl
#define dv(name, value) cerr << (name) << " is " << (value) << endl
#define da(v)  cerr << "["; REPI(itr, v){cerr << *itr << (itr != --v.end() ? ", " : "");} cerr << "]" << endl

const string YES = "Yes";
const string NO = "No";

void solve(long long N, long long M){
  cout << (N == M ? YES : NO) << endl;
}

signed main(){
  long long N;
  scanf("%lld",&N);
  long long M;
  scanf("%lld",&M);
  solve(N, M);
}
