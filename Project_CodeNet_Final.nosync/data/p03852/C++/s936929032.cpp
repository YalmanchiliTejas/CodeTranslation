#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  
  char c;
  cin >> c;

  char boin[] = {'a','e','i','o','u'};

  string ans = "consonant";
  rep(i, 5){
    if(c == boin[i]) ans = "vowel";
  }

  cout << ans << endl;

}