#include <iostream>

using namespace std;

int main(){
  int n, l, r;

  while(1){
    cin >> n >> l >> r;
    if(n == 0 ) break;
    
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int ansidx = -1, ans = 0;
    for(int x = l; x <= r; x++){
      for(int j = 0; j < n; j++){
        if( x % a[j] == 0 && x >= a[j]){
          ansidx = j;
          break;
        }
      }
      if(ansidx%2 == 0) ans++;
      if(ansidx == -1 && n % 2 == 0) ans++;
      ansidx = -1;
    }

    cout << ans << endl;
  }
  return 0;
}

