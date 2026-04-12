#include<iostream>

using namespace std;

int main(){
  int i,j;
  int a,b,k,c1[100],c2[100];
  char g[100][100];
  
  for(a=0;a<100;a++){
    c1[a]=0;
    c2[a]=0;
  }
  
  cin>>i>>j;
  for(a=0;a<i;a++){
    for(b=0;b<j;b++){
      cin>>g[a][b];
    }
  }
  
  
  for(a=0;a<i;a++){
    for(b=0;b<j;b++){
      if(g[a][b]=='.'){
        c1[a]++;
        c2[b]++;
      }
    }
  }
  
 for(a=0;a<i;a++){
    if(c1[a]==j) {
      continue;}
    else{
    for(b=0;b<j;b++){
      if(c2[b]==i)
        continue;
      else
        cout<<g[a][b];
    }
    cout<<endl;}
  }
  
  return 0;
}