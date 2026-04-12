#include <bits/stdc++.h>
using namespace std;


#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

/* vector<int> A(N); 
    vector<pair<int, int> > tasks; ＃ソートした場合、１つ目でソート
　tie(b, a) = p.at(i); #pairを分割
    tasks.emplace_back(b, a)  ＃配列tasksの最後に(b,a)を追加
　xの二乗:  pow(x, 2.0) 
    小さい順: sort(v.begin(), v.end());
    大きい順: reverse(v.begin(), v.end());
    int: -2,147,483,648 ～ 2,147,483,647
    ll: -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807
    // int型の2次元配列(3×4要素の)の宣言
    vector<vector<int>> data(3, vector<int>(4));
*/
 
int main() {
  
  int count=0, ans=0;
  string D;
  cin >> D;
  
  if( D.at(0) != D.at(1) ) count++;
  if( D.at(2) != D.at(1) ) count++;
  
  if (count >=1) cout << "Yes" << endl;
  else cout << "No" << endl;
}
