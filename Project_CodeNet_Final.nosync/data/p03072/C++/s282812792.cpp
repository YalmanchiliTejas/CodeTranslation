#include <iostream>
using namespace std;
int main(){
  int n, ans=1, max=0;
  cin >> n;
  int h[n];
  for(int i=0; i<n; i++)
    cin >> h[i];
  max=h[0];
  for(int i=1; i<n; i++){
    if(h[i]>=max){
      ans++;
      max=h[i];
    }
  }
  cout << ans;
  return 0;
}
