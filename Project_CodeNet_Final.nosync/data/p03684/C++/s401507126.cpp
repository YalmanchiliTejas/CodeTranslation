#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tri;
typedef vector<int> vi;
typedef set<int> si;
const int inf = 1e9;
const int mod = 1e9+7;

struct UF{
  vi v;
  void vset(int n){
    v.clear();
    FOR(i, 0, n) v.pb(i);
  }
  UF(int n){
    vset(n);
  }
  bool merge(int a, int b){
    int _a = find(a), _b=find(b);
    if(_a == _b) return false;
    if(_a > _b) swap(_a, _b);
    v[_b] = _a;
    return true;
  }
  int find(int a){
    int _a = v[a];
    if(a == _a)return a;
    _a = find(_a);
    v[a] = _a;
    return _a;
  }
  bool same(int a, int b){
    return (find(a) == find(b));
  }
};

int N;
pii x[100005], xy[2][100005];
tri z[200005];
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  UF uf = UF(N);
  FOR(i, 0, N){
    int a, b;
    cin >> a >> b;
    xy[0][i] = pii(a, i);
    xy[1][i] = pii(b, i);
  }
  int iz=0;
  FOR(i, 0, 2){
    sort(xy[i], xy[i] + N);
    FOR(j, 1, N){
      z[iz] = tri(xy[i][j].first - xy[i][j-1].first, pii(xy[i][j].second, xy[i][j-1].second));
      iz++;
    }
  }
  sort(z, z+iz);
  ll ans = 0;
  FOR(i, 0, iz){
    if(uf.merge(z[i].second.first, z[i].second.second)) ans += z[i].first;
  }
  cout << ans << "\n";
}