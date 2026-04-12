#include <bits/stdc++.h>
using namespace std;
char a;
string b = "aiueo";
int c = 0;
int i;

int main(){
  cin>>a;
  for(i=0;i<5;++i){
    if(a == b[i]){
      cout<<"vowel"<<endl;
      c = 1;
      break;
    }
  }
  if(c == 0){
    cout<<"consonant"<<endl;
  }
}