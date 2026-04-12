#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000

void solve(){
   cin.tie(0);
   ios::sync_with_stdio(false);
   ll h , w;
   cin>>h>>w;
   std::vector< vector<char> > v(h,vector<char>(w));
   rep(i,h)rep(j,w) cin>>v[i][j];
   ll cnt=0;
   rep(i,h)rep(j,w) if(v[i][j] == '#') cnt++;
   if(cnt == h + w - 1) cout<<"Possible"<<endl;
   else cout<<"Impossible"<<endl;
}
int main(){
  solve();
  return 0;
}

