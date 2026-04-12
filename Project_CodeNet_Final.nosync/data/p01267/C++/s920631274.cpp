#include <iostream>
using namespace std;

int main(void){
  int n, a, b, c, x, ind, cnt, i;
  int ylst[100];
  while(1){
    cin >> n >> a >> b >> c >> x;
    if(n == 0) break;
    for(i=0;i<n;i++) cin >> ylst[i];
    ind = 0;
    cnt = -1;
    while(ind < n and cnt <= 10000){
      if(x == ylst[ind]) ind++;
      x = (a * x + b) % c;
      cnt++;
    }
    if(cnt <= 10000){
      cout << cnt << endl;
    }else{
      cout << -1 << endl;
    }
  }
  return 0;
}

