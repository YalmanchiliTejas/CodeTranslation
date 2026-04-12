#include <iostream>
using namespace std;

int main(){
  int N,ans;
  cin >> N;
  ans = 800*N - ((int)(N/15))*200;
  cout << ans << endl;
  return 0;
}
