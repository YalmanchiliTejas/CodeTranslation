#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;

int main() {

  int x, y, z;
  cin >> x >> y >> z;
  
  int tmp = z;
  int ans = 0;
  for(int i = 0; i < 1000000; i++) {
    if(tmp + y + z <= x) {
      tmp = tmp + (y+z);
      ans++;
    } 
  }
  cout << ans << endl;
}