#include <iostream>
#include <string>

using namespace std;

int main(){

  int i;
  string S,T,U;
  
  //cin>>S>>T;
  cin>>S;
  //cin>>U;

  //  cout<<S<<endl;
  
    for(i=0;i<S.length();i++){
      //     cout<<i<<S[i]<<endl;
  }
    for(i=0;i<S.length()-1;i++){
  if(S[i]!=S[i+1]){
    cout<<"Yes"<<endl;
    return 0;
  }
  }
  cout<<"No"<<endl;
  return 0;
}
