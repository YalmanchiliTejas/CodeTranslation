    #include <bits/stdc++.h>
    using namespace std;
    #define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S; cin >> S; // 入力文字列
  string R = "consonant"; // 計算結果 or vowel
  
  rep(i,S.size()){
    if (S.at(i)=='a'|| 
        S.at(i)=='e'|| 
        S.at(i)=='i'|| 
        S.at(i)=='o'|| 
        S.at(i)=='u') {
      R = "vowel";
    }
  }
  cout << R << endl;
}
