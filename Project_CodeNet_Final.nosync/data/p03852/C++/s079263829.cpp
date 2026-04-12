#include <bits/stdc++.h>
using namespace std;
int main(){
  char c;
  string A="aiueo";
  int a=0;
  cin>>c;
  for(int i=0;i<5;i++){
    if(c==A[i]) a=1;
  }
  if(a==1) cout<<"vowel"<<endl;
  else cout<<"consonant"<<endl;
  return 0;
}