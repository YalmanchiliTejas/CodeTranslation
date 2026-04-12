#include <iostream>
#include <string>
using namespace std;
int main(){
  int N,k;
  string S;
  cin >> N >> S >> k;
  char C = S[k-1];
  for(int i = 0; i < N; i++){
    if (S[i] != C){
      S[i] = '*';
    }
  }
  cout << S << endl;
  return 0;
}