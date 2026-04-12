#include <iostream>
#include <algorithm>
using namespace std;

int main(){

  int n, s;

  while(cin >> n, n){
    int sum = 0;
    int max_s = -1, min_s = 10001;
    for(int i = 0; i < n; i++){
      cin >> s;
      min_s = min(min_s, s);
      max_s = max(max_s, s);
      sum += s;
    }
    sum = sum - max_s - min_s;
    sum /= (n - 2);
    cout << sum << endl;
  }
  return 0;
}
