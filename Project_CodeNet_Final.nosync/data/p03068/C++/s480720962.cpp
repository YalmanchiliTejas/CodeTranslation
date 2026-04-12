#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N;
  string s;
  cin>>s;
  cin>>K;
  for(int i = 0;i<N;i++){
    if(s.at(i) != s.at(K-1)){
      cout << "*";
    }
    else{
      cout << s.at(K-1);
    }
  }
  cout << endl;
  return 0;
}
  