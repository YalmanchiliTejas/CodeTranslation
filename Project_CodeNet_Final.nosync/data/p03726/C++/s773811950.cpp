#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP rep
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
const ll MOD=1e9+7;

#define rall(X) (X).rbegin(),(X).rend()
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}

int N;
bool pos = false;
set<int> es[114514];
map<int, bool> mem[114514];

bool Solve() {
  cin >> N;
  rep(i, N-1) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    es[u].insert(v);
    es[v].insert(u);
  }
    
  if (N == 2) return false;
  if (N == 3) return true;

  queue<int> que;
  rep(v, N) {
    if (es[v].size() == 1) que.push(v);
  }

  while (!que.empty()) {
    int v = que.front(); que.pop();
    if (es[v].empty()) continue;
    {
    //  return true;
    }

    int u = *es[v].begin();
    for (int w : es[u]) {
      if (w == v) continue;
      es[w].erase(u);
      if (es[w].empty()) return true;
      if (es[w].size() == 1) que.push(w);
    }
  }

  return false;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);

  if (Solve()) puts("First");
  else puts("Second"); 
}
