#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 2147483600
#define long long long // for codeforces

vector<int> vec[10];
vector<bool> visited;

int dfs(int d, int n){
  if(n==1) return 1;
  visited[d]=true;
  int cnt=0;
  for(auto to : vec[d]) if(visited[to]==false){
    cnt += dfs(to, n-1);
  }
  visited[d]=false;
  return cnt;
}

int main(){
  int n,m;
  cin>>n>>m;
  visited.resize(n);
  fill(all(visited), false);
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    vec[a].pb(b);
    vec[b].pb(a);
  }

  cout<<dfs(0,n)<<endl;

  return 0;
}
