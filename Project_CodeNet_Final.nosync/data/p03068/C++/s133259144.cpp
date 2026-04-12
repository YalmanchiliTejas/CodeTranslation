#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string S;
  int K;
  cin >> N >> S >> K;
  char dif = S.at(K-1);
  
  for(int i = 0; i < N; i++){
  	if(S.at(i) != dif){
    	cout << "*";
    }else{
    	cout << S.at(i);
    }
  }
  cout << endl;
}