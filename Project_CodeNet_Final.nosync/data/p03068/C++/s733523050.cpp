#include <iostream>
using namespace std;
int main(){
  int N,K;
  char str[11];
  cin >> N >> str >> K;
  for(int i=0;i<N;i++){
    if(str[i]!=str[K-1])cout << "*";
    else cout << str[i];
  }
  cout << endl;
  return 0;
}