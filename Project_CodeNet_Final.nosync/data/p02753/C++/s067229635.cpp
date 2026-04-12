#include <bits/stdc++.h>
using namespace std;

int main() {

  // 配列
  string S; // int型の配列変数vecを宣言
// vector<int> T(N); // int型の配列変数vecを宣言
  cin >> S;

  string ANS;
  ANS = "Yes";
  if(S.at(0)==S.at(1)){
	if(S.at(0)==S.at(2)){
		ANS = "No";
    }
  }
  
  cout << ANS << endl;

}
