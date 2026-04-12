#include <iostream>
 
using namespace std;
 
char ans[5]={'a','i','u','e','o'};
 
int main(){
  string c;
  cin>>c;
  for(int i=0;i<5;i++){
    if(c[0]==ans[i]){
      cout<<"vowel"<<endl;
      return 0;
    }
  }
  cout<<"consonant"<<endl;
  return 0;
}