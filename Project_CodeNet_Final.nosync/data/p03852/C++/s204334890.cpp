#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;
  cin>>c;
  bool a=0;
  if(c=='a'){
  a=1;
  }
    if(c=='i'){
  a=1;
  }
  if(c=='u'){
  a=1;
  }
    if(c=='e'){
  a=1;
  }
  if(c=='o'){
  a=1;
  }
  if(a==1){
  cout<<"vowel"<<endl;
  }
  if(a==0){
  cout<<"consonant"<<endl;
  }
}