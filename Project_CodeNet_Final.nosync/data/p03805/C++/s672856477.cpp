#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // ABC054C - One-stroke Path
  // 自己ループと二重辺を含まないN頂点、M辺の重みなし無向グラフ
  // 全ての頂点を1度だけ訪ねるパスは何通りあるか
  // 解法2：next_permutation
  // N!通りの全探索を行う。1をスタート地点として、2～Nまでの各順列に対してその順番に辺が存在するかどうかを判定
  // 最後まで行けたらansをインクリメント
  int N, M; cin >> N >> M;
  vector<vector<bool> > G(N+1, vector<bool>(N+1, false));
  REP(i, M){
    int a, b; cin >> a >> b;
    G[a][b] = true; G[b][a] = true;
  }
  
  // next_permutationで使用する順列データを準備する
  // 1は固定なので、2からNまでの整数を準備
  vector<int> v(N);
  REP(i, N-1) v[i] = i + 2;

  int ans = 0;
  do{
    int from = 1; bool path = true; // スタート地点は1
    REP(i, N-1){ // permutaiton分だけループ
      int to = v[i];
      if(G[from][to]){
        from = to; // pathがあれば、toをfromにセット
      }else{
        path = false; break; // pathがなければpath=falseにしてbreak
      }
    }
    if(path) ans++; // path=trueならansをインクリメント
  }while(next_permutation(v.begin(), v.end())); 
  
  cout << ans << endl;
}