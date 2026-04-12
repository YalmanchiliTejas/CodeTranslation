#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  long A[N];
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  long Sum[N];
  Sum[N - 1] = A[N - 1];
  for(int i = N - 2; i > 0; i--){
    Sum[i] = (Sum[i + 1] + A[i]) % (int(pow(10, 9)) + 7);
  }
  long ans = 0;
  for(int i = 0; i < N - 1; i++){
    ans += (A[i] * Sum[i + 1]) % (int(pow(10, 9)) + 7);
    ans %= (int(pow(10, 9)) + 7);
  }
  cout << ans << endl;
  return 0;
}