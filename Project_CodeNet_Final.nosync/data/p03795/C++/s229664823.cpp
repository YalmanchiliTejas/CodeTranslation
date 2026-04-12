#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int sum=0;
  int j=1;
  for(int i=1;i<=N;i++){
    sum+=800;
    if(i==(j*15)){
      sum-=200;
      j++;
    }
  }
  cout<<sum<<endl;
}