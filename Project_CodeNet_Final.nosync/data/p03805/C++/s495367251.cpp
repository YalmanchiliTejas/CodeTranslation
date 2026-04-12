#include <bits/stdc++.h>
using namespace std;

#define COUT(x) cout << #x << " = " << (x) << ", "
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
typedef long long ll;
const int MOD = 1000000007;

int N,M;
vector<int> G[50];

int dfs(int n, vector<bool> flag){
  vector<bool> tmpflag = flag;
  tmpflag[n] = true;
  flag[n] = true;
  bool f = true;
  for(int i = 0; i < N; i++){
    f = f & flag[i];
  }
  if(f) return 1;
  int res = 0;
  bool oflag = false;
  for(auto x: G[n]){
    if(tmpflag[x] == false){
      res += dfs(x, tmpflag);
      oflag = true;
    }
  }
  if(oflag == false){
    return 0;
  }else{
    return res;
  }
}

int main(){
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<bool> flag(N, false);
  int ans = dfs(0, flag);
  cout << ans << endl;
}
