//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
  string s;
  cin >> s;
  if(s == "AAA" || s == "BBB"){
    cout << "No";
  }
  else{
    cout << "Yes";
  }
}