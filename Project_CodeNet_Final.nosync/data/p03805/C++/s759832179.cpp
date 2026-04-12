#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
#define PI 3.141592653589793
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
int gcd(int a, int b){//ユークリッドの互除法
  if (a < b) gcd(b,a); //aの方がbよりでかいのが前提
  if (b == 0) return a; //aをbで割り切れたらreturn
  else gcd(b, a % b);
}
const int INF = 1<<30;
const int MOD = 1000000007;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
  int n,m; cin >> n >> m;
  vector<vector<int>> G(n,vector<int>(n,0));
  rep(i,m){
    int a,b; cin >> a >> b;
    a--,b--;
    G[a][b] = 1;
    G[b][a] = 1;
  }
  vector<int> v;
  for(int i = 1; i < n; i++){
    v.push_back(i);
  }
  int ans = 0;
  do{
    int from = 0;
    bool flag = true;
    for(int i = 0; i < v.size();i++){
      int to = v[i];
      if(G[from][to] == 0) flag = false;
      from = to;
    }
    if(flag) ans++;
  }while(next_permutation(v.begin(), v.end()));// 次の順列を生成
  
  cout << ans << endl;
  
  return 0;
}