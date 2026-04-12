#include <bits/stdc++.h>
using namespace std;

int main() {
    long long inf  = 1e9+7;
  int N;
  cin >> N;
  vector<long long int> A(N);
  long long int sumA = 0;
  for (int i=0; i < N; i++) {
    cin >> A[i];
    A[i] = A[i] % inf;
    sumA = sumA + A[i];
    sumA = sumA % inf;
  }
  long long int sumanijo = 0;
  sumanijo = sumA * sumA % inf;
  long long int nijosum = 0;
  for (int i=0; i < N; i++) {
    nijosum = nijosum + A[i] * A[i] % inf;
    nijosum = nijosum % inf;
  }
  long long int sum = 0;
  long long int sa = 0;
  sa = sumanijo - nijosum;
  while (true){
    if(sa < 0) {
      sa = sa + inf;
    } else {
      break;
    }
  }
  sum = sa % inf;
  if (sum % 2 == 1){
    sum = (sum + inf)/2;
  } else{
    sum = sum/2;
  }
  cout << sum << endl;
}