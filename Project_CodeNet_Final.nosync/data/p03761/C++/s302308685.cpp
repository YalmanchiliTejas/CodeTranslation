#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }

  vector<int> alphabet(26, 0);
  for(int i = 0; i < n; ++i) {
    for(int j = 'a'; j <= 'z'; ++j) {
      int cnt = 0;
      for(int k = 0; k < S[i].size(); ++k) {
        if(S[i][k] == (char)j) {
          if(i == 0) {
            alphabet[j-'a']++;
          }
          else{
            cnt++;
          }
        }
      }
      // cout <<j-'a' << (char)j << " : " << alphabet[j-'a'] << " : " << cnt << endl;
      if(i != 0) {
        alphabet[j-'a'] = min(alphabet[j-'a'], cnt);
      }
    }
  }

  for(int i = 0; i < alphabet.size(); ++i) {
    for(int j = 0; j < alphabet[i]; ++j) {
      cout << (char)(i + 'a');
    }
    // cout << (char)(i + 'a') << ": " << alphabet[i] << endl;
  }
  cout << endl;

  return 0;
}
