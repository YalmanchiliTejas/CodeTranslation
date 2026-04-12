#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int max=0;
  int ans=0;
  for(int i=0;i<N;i++){
    int H;
    cin >> H;
    if(max<=H){
      ans++;
      max=H;
    }
  }
  cout << ans << endl;
  return 0;
}
