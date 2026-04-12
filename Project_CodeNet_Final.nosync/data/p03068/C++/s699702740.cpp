#include <iostream>
using namespace std;

int N,K;
string S;
int main(){
  cin >> N >> S >> K;
  for(int i=0;i<N;i++){
    if(S[i]!=S[K-1]) cout << '*';
    else cout << S[i];
  }
  cout << endl;
}