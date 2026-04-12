#include<iostream>
#include<algorithm>
#include<vector>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define reps(i,f,n) for(int i = f; i <= n; ++i)
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;
using PII=pair<int,int>;
using PPI=pair<int,PII>;

class UF{
public:
  vector<int> p; //parent->マイナスだとルート． 
  UF(int n){p.resize(n, -1);}
  int root(int x){return p[x] < 0 ? x : p[x] = root(p[x]);}

  bool same(int x, int y){return root(x) == root(y);}

  void unite(int x, int y){
    x = root(x);y = root(y);
    if(x == y) return;
    if( p[y] < p[x]) swap(x,y); //p[x] < p[y]にする xの方が絶対値がおっきい
    p[x] += p[y];
    p[y] = x;
  }
  int size(int x){
    return -p[root(x)];
  }
};

vector<PPI> edges;

int main(void){
  int n;
  vector<PII> X;
  vector<PII> Y;
  int x, y;

  cin >> n;
  rep(i, n){
    cin >> x;
    cin >> y;
    X.eb(PII(x, i));
    Y.eb(PII(y, i));
  }

  sort(all(X));
  sort(all(Y));

  rep(i,n-1){
    edges.eb(PPI(X[i+1].first - X[i].first, PII(X[i].second, X[i+1].second)));
    edges.eb(PPI(Y[i+1].first - Y[i].first, PII(Y[i].second, Y[i+1].second)));
  }

  sort(all(edges));
  UF uf(n);
  int ans = 0;
  rep(i, edges.size()){
    x = edges[i].second.first;
    y = edges[i].second.second;
    if(!uf.same(x,y)){
      uf.unite(x, y);
      ans += edges[i].first;
    }
  }

  cout << ans << endl;

  return 0;
}
