#include <iostream>
#include <string>

using namespace std;

int main(){
  int K, N;
  string S;
  cin >> N >> S >> K;
  for(int i=0;i < S.length();i++){
    if(S[i] != S[K-1]){
      cout << "*";
    }else{
      cout << S[i];
    }
  }
  cout << endl;
  return 0;
}