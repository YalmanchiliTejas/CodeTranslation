#include <iostream>
using namespace std;

int main(){
  int n, t, e;

  while(cin >> n >> t >> e){
    int ans = -1;

    for(int i = 0; i < n; i++){
      int x;
      cin >> x;

      for(int j = t - e; j <= t + e; j++){
        if(j % x == 0){
          ans = i + 1;
          break;
        }
      }
    }

    cout << ans << endl;
  }
}