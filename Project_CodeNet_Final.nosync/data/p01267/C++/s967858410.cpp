#include <iostream>
using namespace std;

int main(){

  int n, a, b, c, x;
  int y[110];

  while(cin >> n >> a >> b >> c >> x, n|a|b|c|x){
    int ans = 0;
    for(int i = 0; i < n; i++){
      cin >> y[i];
    }
    int idx = 0;
    int i;
    for(i = 0; i <= 10000; i++){
      if(y[idx] == x){
        idx++;
      }
      if(idx == n) break;
      x = (a * x + b) % c;
    }
    if(i < 10001){
      cout << i << endl;
    }else{
      cout << -1 << endl;
    }
  }
  return 0;
}
