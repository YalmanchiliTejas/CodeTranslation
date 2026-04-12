#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(x,y) (x=min(x,y))
#define chmax(x,y) (x=max(x,y))
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}
int g[9][9];
int main(){
	int n, m;
  cin>>n>>m;
  rep(i, m){
    int a, b;
    cin>>a>>b; a--; b--;
    g[a][b] = g[b][a] = 1;
  }
  vector<int> p(n);
  rep(i, n) p[i] = i;
  int res = 0;
  do{
    int r = 1;
    rep(i, n-1) r *= g[p[i]][p[i+1]];
    res += r;
  } while(next_permutation(p.begin()+1, p.end()));
  cout<<res<<endl;
	return 0;
}
