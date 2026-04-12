#include <iostream>

using namespace std;
#define MOD 1000000000 + 7
int main(){
  int N;
  cin >> N;
  long long A[N];
  long long sum(0);
  long long sum_A(0);
  for(int i = 0 ; i < N ; ++i)
  {
    cin >> A[i];
    sum += (A[i] * sum_A) % (MOD);
    sum %= (MOD);
    sum_A += A[i];
    sum_A %= (MOD);
  }
  cout << sum << endl;
  return 0;
}