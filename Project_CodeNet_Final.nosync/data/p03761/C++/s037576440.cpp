#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  for(int i = 0; i < N; ++i){
    cin >> S[i];
    sort(S[i].begin(), S[i].end());
  }
  vector<int> id(N,0);
  char c = 'a';
  string ans;
  while(c <= 'z'){
    bool f = true;
    for(int i = 0; i < N; ++i){
      while(id[i] < S[i].length() && S[i][id[i]] < c) ++id[i];
      if(id[i] >= S[i].length() || S[i][id[i]] != c) f = false;
      else ++id[i];
    }
    if(f) ans += c;
    else ++c;
  }
  cout << ans << endl;
  return 0;
}
