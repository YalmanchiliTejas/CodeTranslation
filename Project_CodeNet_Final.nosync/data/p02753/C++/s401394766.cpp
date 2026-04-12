#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
bool debug = false;

int main() {
  string S ; cin >> S; // 入力文字列
  string Ans = "Yes";

  if ( S == "AAA" || S== "BBB") {
    Ans = "No";
  }

  cout << Ans << endl;
  
}

