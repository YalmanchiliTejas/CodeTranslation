#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
  int N,K;
  cin >> N;
  string S;
  cin >> S;
  cin >> K;

  char a = S[K-1];

  for(int i=0; i<N; i++){
    if(S[i]!=a){
      S[i] = '*';
    }
  }

  cout << S << endl;
}