#include <iostream>
using namespace std;

void getResult(const int strSize, const int nonReplaceIndex, string &str){
  char nonReplace = str[nonReplaceIndex];
  for(int i = 0; i < strSize; i++){
    if(str[i] != nonReplace) str[i] = '*';
  }
}

int main(){
  int N, K;
  string S;
  cin >> N >> S >> K;
  
  getResult(N, K-1, S);
  cout << S;
  return 0;
}