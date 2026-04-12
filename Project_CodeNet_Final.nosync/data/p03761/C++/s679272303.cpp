#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define ALLTRUE(xs) all_of(ALL(xs),[](bool x){return x;})
#define AND(x,y,z) set_intersection((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define ANYTRUE(xs) any_of(ALL(xs),[](bool x){return x;})
#define CONCAT(x,y) (x).insert((x).end(),(y).begin(),(y).end())
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define FOR(i,a,b) for (int i=(int)(a);i<(int)(b);++i)
#define OR(x,y,z) set_union((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define OUT(x) cout<<x<<endl
#define REP(i,n) FOR(i,0,n)

typedef long long ll;
typedef pair<ll, ll> P;

struct edge { int to,cost; };

int main() {
  int N;cin>>N;
  vector<string> SS(N);
  REP(i,N) {
    cin>>SS[i];
    sort(ALL(SS[i]));
  }
  // 最初の文字列に出てくる文字ごとに、最小の数を検索していく
  set<char> cs;
  REP(i,SS[0].size()) cs.insert(SS[0][i]);
  string res;
  for (char c:cs) {
    int tmp = INT_MAX;
    REP(i,N) {
      int cnt = count(ALL(SS[i]),c);
      tmp = min(tmp, cnt);
    }
    REP(i,tmp) res.push_back(c);
  }
  OUT(res);

  return 0;
}