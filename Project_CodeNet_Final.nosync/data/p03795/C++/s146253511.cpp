#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<n; ++i)
typedef long long ll;
//必要な宣言
#define MAX 100000

//問題をよく読もう！
//論理的に考えよう！
//サンプルを確認しよう!
//絶対に諦めるな！
//工夫をしろ！
int main() {
  int N;
  cin >> N;
  cout << N*800-200*(N/15) << endl;

  return 0;
}
