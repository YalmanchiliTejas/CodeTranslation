#include <iostream>

using namespace std;

int main(){
  int N, K, i;
  cin >> N;
  char S[N], tmp;
  for(i=0; i<N; i++) cin >> S[i];
  cin >> K;
  tmp = S[K-1];
  for(i=0; i<N; i++){
    if(tmp != S[i]) S[i] = '*';
  }
  for(i=0; i<N; i++) cout << S[i];
  cout << endl;
  return 0;
}
