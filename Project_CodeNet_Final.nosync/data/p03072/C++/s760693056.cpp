#include<iostream>

using namespace std;
int main(){
  int N;
  int H[20]={};
  int count=0;
  int i,j;
  int flag;
  
  cin >> N;
  
  for(i=0;i<N;i++){
    cin >> H[i];
  }
  
  for(i=0;i<N;i++){
    flag=0;
    for(j=0;j<i;j++){
      if(H[i]<H[j]){
      	flag=1;
        break;
      }
    }
    if(flag==0){
      count++;
    }
  }
  cout << count;
  return 0;
}