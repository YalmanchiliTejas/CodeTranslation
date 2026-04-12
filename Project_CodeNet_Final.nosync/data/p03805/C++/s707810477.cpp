#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T> void operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) cin >> e; }

typedef long long ll;
int const inf = 1<<29;

int N, M;
vector<vector<int>> G;
int ans = 0;

void dfs(int curr, std::set<int>& st) {

  if (st.size() == N) {
    ans++;
    return;
  }

  rep(i, G[curr].size()) {
    int next = G[curr][i];
    if (st.count(next)) {
      continue;
    }
    st.insert(next);
    dfs(next, st);
    st.erase(next);
  }
}

int main() {

  cin >> N >> M;
  G.resize(N);
  rep(i, M) {
    int a, b; cin >> a >> b;
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }

  set<int> st; st.insert(0);
  dfs(0, st);

  std::cout << ans << "\n";
  
  return 0;
}