#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char s;
  cin >> s; // 変数sで入力を一行受け取る
  
  if (s=='a' || s=='e' || s=='i' || s=='o' || s=='u' ){
    cout << "vowel " << endl;
  }else{
    cout << "consonant " << endl;
  }
}