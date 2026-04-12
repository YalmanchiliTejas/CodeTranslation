#include <iostream>
#include <string>
using namespace std;

int main(){
  while(1){
    string S;
    cin >> S;
    if(S=="#")break;
    int che=0;
    string R="yuiophjklnm";
    int a=0;
    for(int i=0;i<S.size();i++){
      bool ok=false;
      for(int j=0;j<R.size();j++){
        if(S[i]==R[j]){
          ok=true;
          break;
        }
      }
      if(a==0){
        if(ok){
          a=1;
        }else{
          a=-1;
        }
        continue;
      }
      if(ok){
        if(a==-1){
          che++;
          a=1;
        }
      }else{
        if(a==1){
          che++;
          a=-1;
        }
      }
    }
    cout << che << endl;
  }
}

