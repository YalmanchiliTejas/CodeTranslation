#include<iostream>
#include<vector>
using namespace std;
 
int main() {
  int c;
  cin >> c;

  vector<int> h(c);
  int k=0;

  cin >> h[0];
  k = h[0];
  int ans = 1;
  for(int i=1; i<c; i++) {
    cin >> h[i];
    if(k <= h[i]) {
      ans++;
      k = h[i];
    }
  }

  cout << ans << endl;
}
