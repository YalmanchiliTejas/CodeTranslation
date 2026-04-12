#include <iostream>
#include <string>
using namespace std;
int main(){
  string S;
  cin>>S;
  int l=S.size();
  for(int i=0;i<l-1;i++){
    if(S[i]=='A'&&S[i+1]=='C'){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}