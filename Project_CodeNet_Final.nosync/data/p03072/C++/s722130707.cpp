#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
  int N;
  cin >> N;
  int H[N];
  for(int i=0; i<N; i++) cin >> H[i];
  
  int ans = 0;
  for(int cnt0=0; cnt0<N; cnt0++){
    bool f = true;
    for(int cnt1=0; cnt1<cnt0; cnt1++){
      if(H[cnt0] < H[cnt1]) {
        f = false;
        break;
      }
    }
    if(f) ans++;
  }
  
  cout << ans << endl;
}