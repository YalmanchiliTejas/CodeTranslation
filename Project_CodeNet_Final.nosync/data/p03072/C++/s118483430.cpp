#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> H(n);
  for(int i = 0; i<n; i++){
    cin >> H[i];
  }
  int ans = 0;
  for(int i = 0; i<n; i++){
    bool flag = true;
    for(int j = 0; j<=i; j++){
      if(H[i]<H[j])flag = false;
    }
    if(flag) ans++;
  }
  cout << ans << endl;
  return 0;
}
