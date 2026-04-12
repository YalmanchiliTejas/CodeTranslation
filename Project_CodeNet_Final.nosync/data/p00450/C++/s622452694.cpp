#include <iostream>
using namespace std;

int main() {
  while(1) {
    int n;
    cin >> n;
    if(n == 0) break;
    int mp[100001] = {};
    
    for(int i=0;i<n;i++) {
      int a;
    cin >> a;
    mp[i] = a;
    if(i%2 == 1){
      int j = i-1;
      while(mp[j] != a) mp[j] = a,j--;
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++) if(mp[i] == 0) ans++;
  cout << ans <<endl;
  }

    return 0;
}