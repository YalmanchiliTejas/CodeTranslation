#include <iostream>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int h[n];
  for(int i = 0; i<n ; i++){
    cin >> h[i];
  }
  int biggest = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(h[i] >= biggest){
      cnt++;
      biggest = h[i];
    }
  }
  cout << cnt << "\n";
  return 0;
}
