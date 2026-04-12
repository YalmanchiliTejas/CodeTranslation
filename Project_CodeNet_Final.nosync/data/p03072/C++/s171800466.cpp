#include<iostream>
using namespace std;
int main() {
  int n, h, max=0, ans=0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> h;
    if(h >= max){
      max = h;
      ans++;
    }
  }
  cout << ans;
  return 0;
}