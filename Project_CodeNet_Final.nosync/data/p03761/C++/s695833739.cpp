#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  
  string alfa = "abcdefghijklmnopqrstuvwxyz";
  string S;
  
  vector<int> kazu(26, 100); //最小で何回出てきたか
  int a = 0;
  for( int i = 0; i < N; i++ ){
    cin >> S;
    for( int i = 0; i < 26; i++ ){
      a = count(S.begin(), S.end(), alfa.at(i));
      kazu.at(i) = min(kazu.at(i), a);
    }
  }
  
  string ans;
  for( int i = 0; i < 26; i++ ){
    for( int j = 0; j < kazu.at(i); j++ ){
      ans += alfa.at(i);
    }
  }
  cout << ans << endl;
  
}
