#include <iostream>
using namespace std;

int main() {
  long int N, A, ans = 0, num = 1000000007, sum = 0;
  cin >> N;
  for(int i= 0; i<N; i++){
    cin >> A;
    ans = (ans + A*sum)%num;
    sum = (sum + A)%num;  
  }
  cout << ans << endl;
  return 0;
}