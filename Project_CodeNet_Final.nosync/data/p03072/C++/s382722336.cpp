#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin >> N;
  vector<int> H(N, 0);
  int ans = 0;
  for(auto& h : H){
    cin >> h;
    if(*max_element(H.begin(), H.end()) == h) ans++;
  }
  cout << ans << endl;
  return 0;
}