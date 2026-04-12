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

#define INF 123456789

vector<int> vec[100000];
int memo[100000]; //自分以下の子の個数

bool suc = false;

int dfs1(int d, int from){
  memo[d]=1;
  for(auto to : vec[d]) if(to!=from){
    memo[d] += dfs1(to, d);
  }
  return memo[d];
}

void dfs2(int d, int from, int par=0){
  int cnt = 0;
  if(par%2==1) cnt++;
  for(auto to : vec[d]) if(to!=from) if(memo[to]%2==1) cnt++;
  if(cnt>=2){ suc=true; return;}
//dbg(mp(d,cnt));
  for(auto to : vec[d]) if(to!=from) par += memo[to];
  for(auto to : vec[d]) if(to!=from){
    dfs2(to, d, par - memo[to]+1);
  }
}

bool solve(){
  int n;
  cin>>n;
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--;b--;
    vec[a].pb(b);
    vec[b].pb(a);
  }

  dfs1(0,-1);
  dfs2(0,-1);

  if(suc) return true;
  else return false;
}

int main(){
  if(solve()) cout << "First" << endl;
  else cout << "Second" << endl;
  return 0;
}
