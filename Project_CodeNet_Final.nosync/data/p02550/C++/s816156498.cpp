#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;

//定数
//円周率
const double pi = 3.141592653589793238462643383279;
//天井
const int INF = 1000000000; // = 10^9
const ll LINF = 100000000000000000; // = 10^17
//ABC文字列
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZABC";
const string abc = "abcdefghijklmnopqrstuvwxyzabc";
//よくあるmodくん
const ll MOD = 1000000007; // = 10^9 + 7
//前処理テーブルの大きさ指定
const int MAX = 1200000; // = 10^6 + 2*(10^5)
//ちなみに、1024MBで持てる最大長の配列は10^8程度

//データ構造
//隣接リスト用構造体（有向グラフ向け）
struct edge {
  ll to; // E.toでその辺の終点へアクセスできる。
  ll cost; // e.costでその辺の重みにアクセスできる。
};
//Union_Find木
struct UnionFind {
  vector<int> UF; // UF.at(i) : iの親の番号
  vector<int> SIZE; // SIZE.at(root(i)) : iと連結されてる要素の数
  UnionFind(int N) : UF(N), SIZE(N, 1) { // 最初は全てが根であるとして初期化
    for(int i = 0; i < N; i++) {
      UF.at(i) = i;
    }
  }
  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (UF.at(x) == x) {
      return x;
    }
    return UF.at(x) = root(UF.at(x));
  }
  void unite(int x, int y) { // xとyの木を併合
    int rx = root(x); // xの根をrx
    int ry = root(y); // yの根をry
    if (rx == ry) {
      return; // xとyの根が同じ(=同じ木にある)時はそのまま
    }
    // xとyの根が同じでない(=同じ木にない)時：小さい方の根を大きい方の根につける。
    if (SIZE.at(rx) < SIZE.at(ry)) {
      UF.at(rx) = ry;
      SIZE.at(ry) += SIZE.at(rx);
      SIZE.at(rx) = 0;
    }
    else {
      UF.at(ry) = rx;
      SIZE.at(rx) += SIZE.at(ry);
      SIZE.at(ry) = 0;
    }
  }
  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す。
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
  int size(int x) { // xと連結されてる要素の数を返す。
    return SIZE.at(root(x));
  }
};

//関数 (計算量)
//ctoi (O(1))
int ctoi(char c){
  if (c == '0') return 0;
  if (c == '1') return 1;
  if (c == '2') return 2;
  if (c == '3') return 3;
  if (c == '4') return 4;
  if (c == '5') return 5; 
  if (c == '6') return 6;
  if (c == '7') return 7;
  if (c == '8') return 8;
  if (c == '9') return 9;
  return -1;  
}
//to_char (O(1))
char to_char(int i){
  if (i == 0) return '0';
  if (i == 1) return '1';
  if (i == 2) return '2';
  if (i == 3) return '3';
  if (i == 4) return '4';
  if (i == 5) return '5';
  if (i == 6) return '6';
  if (i == 7) return '7';
  if (i == 8) return '8'; 
  if (i == 9) return '9';
  return ' ';  
}

//メイン処理
int main() {
  cout << fixed << setprecision(16); //精度向上
  //ここまでテンプレ
  ll N;
  ll X, M;
  cin >> N >> X >> M;
  vector<ll> T(M, 0); // その数字が何番目に現れたか
  vector<ll> A(M + 1, 0); // i + 1番目までの和
  ll MX = X;
  ll ans = X;
  T.at(X) = 1;
  A.at(1) = X;
  for (ll i = 1; i < N; i++) {
    MX *= MX;
    MX %= M;
    if (T.at(MX) != 0) {
      ans += ((N - i) / (i + 1 - T.at(MX))) * (A.at(i) - A.at(T.at(MX) - 1));
      if (((N - i) % (i + 1 - T.at(MX))) != 0) {
        ans += (A.at(T.at(MX) + (((N - i) % (i + 1 - T.at(MX)))) - 1)
                - A.at(T.at(MX) - 1));
      }
      break;
    }
    else {
      T.at(MX) = i + 1;
      A.at(i + 1) += A.at(i);
      A.at(i + 1) += MX;
      ans += MX;
    }
  }
  cout << ans << endl;
}