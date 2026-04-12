#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
  int n, ma, mi, sum, k;
  while(cin >> n, n){
    sum = ma = 0; mi = 9999;
    for(int i = 0;i < n; i++){
      cin >> k;
      sum += k;
      ma = max(ma, k); mi = min(mi, k);
    }
    sum = sum - ma - mi;
    cout << sum / (n - 2) << endl;
  }
}
