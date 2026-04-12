#include<bits/stdc++.h>
using namespace std;

int main(){
  int e[101],hoge=0;
  for(int i=0;i<12;i++){
    cin >> e[i];
  }
  sort(e,e+12);
  for(int i=0;i<12;i+=4){
    if(e[i]==e[i+1] && e[i+1]==e[i+2] && e[i+2]==e[i+3]){
      hoge++;
    }
  }
  if(hoge==3){
    cout << "yes\n";
  }else{
    cout << "no\n";
  }
  return 0;
}

