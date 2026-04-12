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
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000

bool solve(int n, int m){
  vector<string> vec(n);
  rep(i,n) cin>>vec[i];

  const int dx[] = {0,1,0,-1};
  const int dy[] = {-1,0,1,0};

  const int tx[] = {n-1, n-1, 0, 0};
  const int ty[] = {0, m-1, m-1, 0};

  int dir=0;
  int x=0, y=0;
  rep(i,4){
    auto ok = [&](int p, int q){
      return p>=0 && q>=0 && p<n && q<m && (vec[p][q]=='.' || vec[p][q]==i);
    };
    int step = 0;
    while(x!=tx[i] || y!=ty[i]){
      int nd = 0;
      while(nd<4 && !ok(x+dx[(dir+nd)%4], y+dy[(dir+nd)%4])) nd++;
      if(nd==4) return false;
      x += dx[(dir+nd)%4];
      y += dy[(dir+nd)%4];
      dir = (dir+nd+3)%4;
      vec[x][y] = i;
      if(step++ > n*m) return false;
    }
  }
  return true;
}

int main(){
  int n,m;
  while(cin>>n>>m, n|m){
    if(solve(n,m)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}