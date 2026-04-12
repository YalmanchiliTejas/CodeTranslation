#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin  >> n;
  int h;
  int maxh = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++){
    cin >> h;
    if (maxh <= h){
      cnt++;
      maxh = h;
    }
  }
  cout << cnt << endl;
  return 0;
}
