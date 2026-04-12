#include<iostream>
#include<vector>
using namespace std;

int main(){

  int n; cin >> n;

  int H[n];
  for(int i = 0; i < n; i++){
    cin >> H[i];
  }

  int ans = 0;
  int max = H[0];

  for(int i = 0; i < n; i++){
    if(H[i] >= max){
      max = H[i];
    //  cout << max << endl;
    //  cout << ans << endl;
      ++ans;
    }
  }
  cout << ans << endl;
}
