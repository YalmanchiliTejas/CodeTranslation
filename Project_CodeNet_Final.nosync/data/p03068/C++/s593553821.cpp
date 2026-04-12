#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  int N,K;
  string S;
  string ans;
  cin >> N >> S >> K;
  for(int i=0;i<N;i++){
    if(S[i] != S[K-1]){
      S[i] = '*';
    }
  }
  cout << S << endl;
}