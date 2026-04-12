#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  string s;
  cin>>n >>s >>k;
  char e=s[k-1];
  
  for(int i=0;i<n;i++){
    if(s[i]==e){
      cout<<e;
    }else{
      cout<<'*';
    }
  }
  cout<<endl;
}