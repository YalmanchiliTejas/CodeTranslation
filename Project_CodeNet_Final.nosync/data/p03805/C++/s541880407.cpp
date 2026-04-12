#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
#define Reve(a) reverse(a.begin(), a.end())
#define PI 3.14159265359
typedef long long ll;
const ll MOD = 1e9+7;

/*ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}*/
/*ll myPow(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}*/

/*ll lcm(ll a, ll b){
  ll g = gcd(a, b);
  b /= g;
  a *= b;
  return a;
}*/
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};


int main(){
  int n, m, a, b; cin >> n >> m;
vector<vector<int>> D(n, vector<int>(n));
  rep(i, m){
    cin >> a >> b;
    D[a-1][b-1]=1; D[b-1][a-1] = 1;
  }
  vector<int> A(n);
  rep(i, n) A[i]=i;
  int ans=0;
  do{
    for(int i=1; i<n; i++){
      if(A[0]!=0) break;
      if(D[A[i-1]][A[i]]!=1) break;
      else if(i==n-1) ans++;
    }
  }while(next_permutation(A.begin(), A.end()));
  cout << ans << endl;
}