#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  int ans=1;
  for (int i=0;i < n; i++) cin >> v.at(i);
  for (int i=1; i < n; i++){
    for (int j=0; j < i; j++){
      if (v.at(i) < v.at(j)) break;
      if (j==i-1) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
  
