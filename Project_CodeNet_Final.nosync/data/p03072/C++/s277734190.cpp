#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int number;
  cin >> number;
  vector<int> heights(number);
  for(int i = 0; i < number; ++i) cin >> heights[i];

  int ans = 0;
  for(int i = 0; i < number; i++){
    bool visible = true;
    for(int j = i -1; j >= 0; j--){
      if(heights[i] < heights[j]){
        visible = false;
        break;
      }
    }
    if(visible) ans++;
  }
  cout << ans << endl;
  return 0;
}