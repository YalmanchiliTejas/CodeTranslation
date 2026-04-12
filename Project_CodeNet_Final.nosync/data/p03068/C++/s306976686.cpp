#include <iostream>
#include <string>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int K;
  cin >> K;

  char mark = S[K-1];

  for (int i=0; i<N; i++){
    if (S[i] != mark){
      S[i] = '*';
    }
  }
  cout << S << endl;
  return 0;
}
