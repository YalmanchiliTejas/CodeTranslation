#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int L=S.size();
  int Ans=0;
  for(int i=0; i<L-1; i++){
    if(S.at(i)=='A' && S.at(i+1)=='C'){
      Ans=1;
      cout << "Yes" << endl;
      break;
    }
  }
  if(Ans==0){
    cout << "No" << endl;
  }
}