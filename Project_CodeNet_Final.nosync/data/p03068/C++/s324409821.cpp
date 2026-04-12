#include <bits/stdc++.h>
using namespace std;

int main() {

  	int N,K;
  	cin >> N;
  string s;
  cin >> s>>K;
  char x;
  x=s.at(K-1);
  
  for(int i=0;i<N;i++){
  if(x!=s.at(i)){
  cout << "*";
  }else{
  cout << x;
  }
  }
  	
}