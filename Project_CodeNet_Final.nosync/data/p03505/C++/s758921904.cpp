#include <iostream>
using namespace std;

int main(void){
  long long int k, a, b;
  cin >> k >> a >> b;

  if(a >= k){ cout << 1 << endl; }
  else if(a <= b){ cout << -1 << endl; }
  else{
    long long int rating = a;
    long long int diff = a - b;
    long long int ans = (k - rating + diff - 1) / diff;
    ans = ans * 2 + 1;
    cout << ans << endl;
  }

  return 0;
}
