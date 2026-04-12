#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define each(a,x) for(auto a : (x))
#define all(a) (a).begin(),(a).end()
#define chmin(a,b) ((a) = min((a),(b)))
#define chmax(a,b) ((a) = max((a),(b)))
#define in_range(x,l,r) ((l)<=(x) && (x)<(r))
#define printvec(a) rep(i,a) cout << a[i] << " \n"[i+1==(a).size()];
#define fs first
#define sc second
#define em emplace
#define eb emplace_back
#define sz size()
#define MP make_pair
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;

const ll INF = 1e8;
const D EPS = 1e-8;
const ll MOD = 1e9+7;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vi> g(n, vi(n,0));
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a][b] = g[b][a] = 1;
  }

  int ans = 0;
  vi p(n);
  rep(i,n) p[i] = i;
  do{
    bool ok = (p[0] == 0);
    rep(i,n-1){
      ok &= (g[p[i]][p[i+1]] > 0);
    }
    if(ok) ans++;
  }while(next_permutation(all(p)));

  cout << ans << endl;
}
