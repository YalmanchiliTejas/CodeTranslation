#include <iostream>
using namespace std;
int r[100]={},c[100]={};
int main(){
  int H,W;
  cin>>H>>W;
  string str[100];
  int i=0,j=0;
  while(i<H){
    j=0;
    cin>>str[i];
    while(j<W){
      if(str[i][j]=='#'){
      r[i]++;
      c[j]++;}
      j++;
    }
    i++;
  }
  i=0;
  while(i<H){
    j=0;if(!r[i]){i++;continue;}
    while(j<W){
      if(c[j])cout<<str[i][j];
      j++;
    }
    i++;
    cout<<endl;
  }
}