#include <iostream>
using namespace std;

int main(){
  int N,K;
  string S;
  cin>>N>>S>>K;
  string s;
  s=S[K-1];
  string ss;
  for (int i=0;i<N;i++){
    ss=S[i];
    if (ss!=s){
      S.replace(i,1,"*");
    }
  }
  cout<<S;
  return 0;
}