#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

/*
string f(int n){
  if (n == 0) return "P";
  else return "B" + f(n - 1) + "P" + f(n - 1) + "B";
}
*/

//レベルiバーガーの厚さ
ll a(int i){
  if (i == 0) return 1;
  else return 2 * a(i - 1) + 3;
}

//レベルiバーガーに含まれるパティの総数
ll p(int i){
  if (i == 0) return 1;
  else return 2 * p(i - 1) + 1;
}

//レベルNバーガーの下からX層に含まれるパティの枚数
ll f(int N, ll X){
  if (N == 0) return 1;
  else if (X == 1) return 0;
  else if (X <= 1 + a(N - 1)) return f(N - 1, X - 1);
  else if (X == 2 + a(N - 1)) return p(N - 1) + 1;
  else if (X <= 2 + 2 * a(N - 1)){
    return p(N - 1) + 1 + f(N - 1, X - 2 - a(N - 1));
  }else return 2 * p(N - 1) + 1;
}

int main(void){
  ll N, X;
  cin >> N >> X;
  cout << f(N, X) << endl;
  return 0;
}
