#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

  int ans,max,n,h;
  ans = 0;
  max = 1;

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> h;
    if(h>=max){
      max = h;
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}