#include <bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i; i < N; i++){
    cin >> H[i];
  }
  int ans = 0;
  int Heighest_Mt = 0;
  
  for (int i = 0; i < N; i++)
    if (H[i] >= Heighest_Mt){
      ans++;
      Heighest_Mt = H[i];
    }
  cout << ans << endl;
}