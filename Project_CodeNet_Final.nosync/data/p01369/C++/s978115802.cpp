#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> h = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0};
  while (1){
    string S;
    cin >> S;
    if (S == "#"){
      break;
    }
    int N = S.size();
    int ans = 0;
    for (int i = 0; i < N - 1; i++){
      if (h[S[i + 1] - 'a'] != h[S[i] - 'a']){
        ans++;
      }
    }
    cout << ans << endl;
  }
}
