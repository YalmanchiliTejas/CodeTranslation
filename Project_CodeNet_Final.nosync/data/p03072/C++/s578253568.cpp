#include <iostream>
#include <vector>

using namespace std;

int main() {
  //input
  int n;
  cin >> n;
  vector<int> a(n); // 大きさが可変な配列
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  //solve
  int ans = n;
  for (int i=0; i<n; i++){
    for (int j=0; j<i; j++){
      if (a[i]-a[j]<0){
        ans--;
        break; // jのfor文から抜ける
      }
    }
  }
  cout << ans << endl;

  return 0;
}
