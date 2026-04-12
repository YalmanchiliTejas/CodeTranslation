#include <iostream>
#include <cmath>
using namespace std;

int mod3(int N, int M) {

}

int main(){
  int N, K;
  char S[10];
  cin >> N;
  cin >> S;
  cin >> K;
  char a;
  a = S[K-1];
  int i;
  for(i = 0;S[i];i++){
  	if(S[i] != a)
  		S[i] = '*';
  }
  for(i = 0;S[i];i++){
  	cout << S[i];
  }
}

