#include<iostream>

using namespace std;

int main(void){

  int N;

  cin >> N;

  long long A[N];
  long long S[N];
  long long m =1e9+7;

  for(int i = 0;i < N;i++){
    cin >> A[i];
  }

  long long sum = 0;


  S[0]=A[0] % m;

  for(int i = 1;i < N;i++){
    S[i] = (S[i-1] + A[i]) % m;
  }


  for(int i = 0;i < N-1;i++){
    sum += A[i]*(S[N-1]-S[i]+m) % m;
    sum = sum % m;
  }

  cout << sum << endl;

  return 0;
}
