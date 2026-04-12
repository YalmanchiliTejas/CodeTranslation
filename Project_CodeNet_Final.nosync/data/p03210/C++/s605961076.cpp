#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
#define all(x) (x).begin(), (x).end()  // sortなどの引数を省略
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define max3(x, y, z) max(x, max(y, z))

#ifdef _MSC_FULL_VER  //デバッグ出力
#define dout cout
#define debug() if (true)
#define check(x) std::cout << "★" << #x << "の値:" << (x) << endl
#define pass(x) std::cout << "☆" << x << endl
#else
#define dout \
  if (false) cout
#define debug() if (false)
#define check(x) \
  if (false) cout << "★" << #x << "の値:" << (x) << endl
#define pass(x) \
  if (false) cout << "☆" << x << endl
#endif
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a==3 or a == 5 or a==7){
    cout << "YES";
  } else {
    cout << "NO";
  }
}
  /*
//よく使うやつ
int N;
cin >> N;
vector<int> list(N);
for (int i = 0; i < N; i++) {
cin >> list[i];
}
// for文
for (int i = 0; i < N; i++) {
}
//配列
vector<int> list;
list.at(i)
vector<vector<int>> list(10, vector<int>(10));
sort(all(list));
sort(all(list), greater<int>());
  //配列の内容表示
dout << "====listの内容====\n";
for (int i = 0; i < N; i++) dout << list[i] << endl;
dout << "====ここまで====\n";
*/
