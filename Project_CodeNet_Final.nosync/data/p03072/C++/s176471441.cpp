#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n;
  int h[40] = {};
  cin >> n;
  for(int i = 0;i < n;i++)
    cin >> h[i];

  int max = h[0];
  int ans = 1;
  for(int i = 1;i < n;i++) {
    if(max <= h[i]){
      max = h[i];
      ans++;
    }
  }
  cout << ans << endl;
}