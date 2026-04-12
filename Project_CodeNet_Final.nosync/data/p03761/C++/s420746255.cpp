#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin >> n;

  int allst[26];
  int stlis[26];

  for (int i = 0 ; i < 26 ; i++){
    allst[i] = 50;
    stlis[i] = 0;
  }
  
  string S;

  for (int i = 0 ; i < n ; i++){

    cin >> S;

    for (int j = 0 ; j < S.size() ; j++){

      stlis[S.at(j) - 'a'] += 1;

    }

    for (int j = 0 ; j < 26 ; j++){

      allst[j] = min(allst[j] , stlis[j]);
      stlis[j] = 0;

    }

  }

  string ans = "";

  for (int i = 0 ; i < 26 ; i++){
    for (int j = 0 ; j < allst[i] ; j++){
      ans += 'a' + i;
    }
  }

  cout << ans << endl;
      
  return 0;

}
