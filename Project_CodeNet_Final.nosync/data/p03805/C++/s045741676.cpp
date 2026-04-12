#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
bool e[10][10]; //bool型の10x10の多次元配列e
int m, n; //int型のmとn
int count_for, count2_if, count_do = 0;
int ar[8] = {1, 2, 3, 4, 5, 6, 7, 8}; //int型の配列ar。要素は8つで1~8
bool has() //bool型のhas()関数
{
  for (int i = 0; i < n - 1; i++) {
    // cout << "ar[";
    // rep(j, 8) cout << ar[j];
    // cout <<  "]" << endl;
    // cout << "配列e: " << ar[i] << "," << ar[i + 1] << endl;
    if (!e[ar[i]][ar[i + 1]]) {
      return 0;
    }
  }
  return 1;
}
int main()
{
  cin >> n >> m;
  rep(i, m) //m回繰り返す。
  {
    int a, b;
    cin >> a >> b;
    e[a][b] = e[b][a] = 1; //多次元配列eのab番目、ba番目に1を入れてく
  }
  int ans = 0;
  do //条件式の前に一度実行
  {
    if (has()) //has()から1がreturnされたら
      ans++; //ans加算
  } while (next_permutation(ar + 1, ar + n)); //ソート済みコンテナクラスの範囲 （first, last) を引数で受け取り、その範囲の要素の次の順列を生成し、arに代入。順列が生成されるうちはtrue。2~8の組み合わせ分has()を繰り返す。最大で5040回
  cout << ans << endl;
  return 0;
}