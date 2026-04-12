#include<iostream>
using namespace std;

int main(){
	int N;
  
  cin >> N;
  
  char S[N+1];
  int K;

  cin >> S >> K;
  
  for(int i = 0; i < N; i++){
  	if(S[K-1] != S[i])
      S[i] = '*';
  }
  
  cout << S << "\n" << endl;
  
	return 0;
}
