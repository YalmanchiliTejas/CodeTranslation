#include <bits/stdc++.h>
// atoi : atoi(変数名.c_str())
// to_string(数値)
// %0桁数d とすると表示桁数が「桁数」に満たない場合に0埋めされる
// find(): int i = 変数名.find(“文字列”) 何番目にあるかを得る
// cout << (条件 ? "Yes" : "No") << endl;
// printf("%02d:%02d:%02d",hour,minute,second);
// 降順 sort(a.begin(),a.end(),greater<int>());
// bitset<ビット数> 変数名;  // すべてのビットが0の状態で初期化される
// bitset<ビット数> 変数名("ビット列");  // 指定したビット列で初期化される
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)

int main(){
  int r,g,b;
  cin >> r >> g >> b;
  int n = 10*g + b;
  if(n % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
