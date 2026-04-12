#include <iostream>
#include <string>
using namespace std;

int main(){
  int N;
  string S;
  int K;
  cin >> N;
  cin >> S;
  cin >> K;
  for(int i=0;i<S.size();i++){
    if(S[i] != S[K-1]){
      S[i] = '*';
    }
  }
  cout << S;
  return 0;
}

