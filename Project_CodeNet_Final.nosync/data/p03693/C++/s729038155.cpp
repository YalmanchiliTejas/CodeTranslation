#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(void){
  int x, y, z;
  cin >> x >> y >> z;
  if((y * 10 + z) % 4 == 0){
    cout << "YES";
  } else {
    cout << "NO";
  }
}
        