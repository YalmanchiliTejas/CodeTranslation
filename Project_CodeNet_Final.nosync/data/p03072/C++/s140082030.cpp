#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int H[N];
  for (int i=0;i<N;i++){
    cin >> H[i];
  }
  int M=0,ans=0;
  for (int i=0;i<N;i++){
    if (M<=H[i]){
      ans++;
      M=H[i];
    }
  }
  cout << ans << endl;
}