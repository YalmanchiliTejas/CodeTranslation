#include <iostream>
// #include <algorithm>
// #include <set>
// #include <map>
using namespace std;

int main()
{
  // 整数の入力
  // int N;
  // cin >> N;
  // N分、入力を取る
  int N;
  cin >> N;
  int h[101];
  for (int i = 0; i < N; i++)
    cin >> h[i];

  int count = 1;
  int max = h[0];
  for (int i = 1; i < N; i++)
  {
    if (max <= h[i])
    {
      count++;
      max = h[i];
    }
  }
  cout << count;
  // スペース区切りの整数の入力
  // int b, c;
  // cin >> b >> c;
  // 文字列の入力
  // string s;
  // cin >> s;
  // 出力
  // cout << (a + b + c) << " " << s << endl;
  return 0;
}