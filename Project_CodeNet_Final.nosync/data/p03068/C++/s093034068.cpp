#include<iostream>
#include<string>
using namespace std;


int main(){
  int N, K;
  string S;

  cin>>N>>S>>K;

  for(int i = 0; i < S.size(); i++) cout<<(S[i]==S[K-1]?S[i]:'*');
  cout<<endl;
  
  return 0;
}
