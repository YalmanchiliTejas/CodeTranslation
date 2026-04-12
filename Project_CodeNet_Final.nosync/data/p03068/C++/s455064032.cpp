#include<iostream>
#include<string>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int K;
  cin >> K;
  char X = S.at(K - 1);
  for(int i = 0; i < N; i++){
    if(S.at(i) != X) S.at(i) = '*';
  }
  cout << S << endl;
}