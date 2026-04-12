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

// DPでパティの枚数保存
// 層はf(N+1) = f(N)*2+3
// P
// [1]
// BPPPB
// [0,1,2,3,3]
// BBPPPBPBPPPBB
// [0,0,1,2,3,3,4,4,5,6,7,7,7]
ll layer_cnt(int N) {
  return 4*pow(2LL,N)-3;
}

ll patty_cnt(int N) {
  return 2*pow(2LL,N)-1;
}

ll dfs(ll N, ll X) {
  if (N==0) return 1;
  if (X==1) return 0;
  if (X<=layer_cnt(N)/2) return dfs(N-1,X-1);
  if (X==layer_cnt(N)/2+1) return dfs(N-1,X-1)+1;
  return patty_cnt(N-1) + 1 + dfs(N-1,X-layer_cnt(N)/2-1);
}

int main() {
  ll N,X;cin>>N>>X;

  OUT(dfs(N,X));

  return 0;
}