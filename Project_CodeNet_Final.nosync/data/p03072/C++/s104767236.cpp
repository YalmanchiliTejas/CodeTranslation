#include <iostream>

using namespace std;

int main(){
  int N, i, ans=0, max;
  cin >> N;
  int H[N];
  for(i=0; i<N; i++) cin >> H[i];
  for(i=0; i<N; i++){
    if(i==0){
      max = H[i];
      ans++;
    }
    if(i != 0 && max<=H[i]){
      max = H[i];
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
