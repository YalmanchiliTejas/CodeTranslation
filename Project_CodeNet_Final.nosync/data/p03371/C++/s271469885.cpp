#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = a * x + b * y;
  for(int i=2; i<=max(x,y)*2; i+=2) {
    int temp_ans = 0;
    if(x >= i / 2 && y >= i / 2) {
      temp_ans = (x - i/2) * a + (y - i/2) * b + i * c;
    }
    if(x >= i / 2 && y < i / 2) {
      temp_ans = (x - i/2) * a + i * c;
    }
    if(x < i / 2 && y >= i / 2) {
      temp_ans = (y - i/2) * b + i * c;
    }
    if(temp_ans != 0 && temp_ans <= ans) ans = temp_ans;
  }
  cout << ans << endl;
}
