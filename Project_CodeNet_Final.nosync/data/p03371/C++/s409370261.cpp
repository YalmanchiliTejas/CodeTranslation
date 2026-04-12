#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int a,b,ab,x,y;
  cin >> a >> b >> ab >> x >> y;
  int c = 2*ab;
  long long ans = 5000 * 100000 * 2;
  for(int i = 0; i <= max(x,y); ++i){
    int cur_x = max(0, x - i);
    int cur_y = max(0, y - i);
    long long cur_ans = c * i + a * cur_x + b * cur_y;
    if(cur_ans < ans){
      ans = cur_ans;
    }
  }
  cout << ans << endl;
}