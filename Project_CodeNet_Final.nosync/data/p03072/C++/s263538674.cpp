#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  int H[N];
  for(int i=0; i<N; i++){
    cin >> H[i];
  }
  int top = H[0];
  int ans = 1;
  for(int i=1; i<N; i++){
    if(H[i] >= top){
      ans++;
      top = H[i];
    }
  }
  cout << ans << endl;
  return 0;
}