#include <iostream>
#include <vector>
using namespace std;
int main(void){
  int n;
  cin >> n;
  
  vector<int>mountain(n);
  
  for(int i=0;i<n;i++){
    cin >> mountain[i];
  }
  
  int ans = 0;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      if(mountain[j] > mountain[i])
        break;
      if(i == j){
        ans++;
      break;
      }
    }
  }
  
  cout << ans << endl;
  
  return 0;
}