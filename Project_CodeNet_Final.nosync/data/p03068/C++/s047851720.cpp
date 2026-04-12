#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
  int N, K;
  string S;
  cin >> N >> S >> K;
  
  string ans = "";
  char a = S[K-1];

  for(int i=0;i<N;i++){
  	if(S[i]!=a){
  		ans += '*';
  	}else{
  		ans += a;
  	}
  }
  
  cout << ans <<endl;



  return 0;
}