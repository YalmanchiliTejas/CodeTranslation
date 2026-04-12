#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  vector<int> nums;

  cin >> n;
  for(int i=0; i<n; i++){
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }

  int max = -1;
  int ans = 1;
  for(int i=0; i<n-1; i++){
    if(max < nums.at(i)) max = nums.at(i);

    if(nums.at(i) <= nums.at(i+1) && nums.at(i+1) >= max){
      ans += 1;
    }
  }
  cout << ans;
}
