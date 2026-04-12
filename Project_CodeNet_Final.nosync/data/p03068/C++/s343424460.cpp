#include<iostream>
#include<string>
using namespace std;
int main(){
  int n,k;
  string str;
  cin>>n>>str>>k;

  char target=str[k-1];
  for(int i=0;i<(int)str.size();i++){
    if(str[i]!=target){
      str[i]='*';
    }
  }

  cout<<str<<endl;
  return(0);
}

