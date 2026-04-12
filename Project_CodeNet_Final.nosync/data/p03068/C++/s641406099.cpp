#include<iostream>
using namespace std;
int main(){
  int n,k;
  char s[10000];
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>s[i];
  cin>>k;
  for(int i=0;i<n;i++){
    if(s[k-1]==s[i])
      cout<<s[i];
    else
      cout<<"*";
  }
  cout<<endl;
  return 0;
}