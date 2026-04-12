#include <bits/stdc++.h>
using namespace std;

int main(){

  int N, ans=1, mx;
  cin >> N;
  int H[N];
  for(int i=0; i<N; i++){
    cin >> H[i];
  }

  mx = H[0];

  for(int i=1; i<N; i++){
    if(H[i]>=mx){
      ans++;
      mx = H[i];
    }
  }

  cout << ans << endl;

  return 0;
}
