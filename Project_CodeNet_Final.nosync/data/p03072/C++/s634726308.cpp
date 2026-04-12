#include<bits/stdc++.h>
using namespace std;
main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N; cin >> N; int H[N]; int Max = 0;
  int ans = 0;
  for(int i = 0; i < N; i++){
    cin >> H[i];
    if(H[i] >= Max) ans++;
    Max = max(Max, H[i]);
  }
  cout << ans;
}