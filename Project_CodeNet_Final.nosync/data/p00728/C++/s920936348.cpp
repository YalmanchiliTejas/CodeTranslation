#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int i,N,total=0,maxdayo,mindayo,box[1000];
  while(1){
  cin>>N;
  if(N==0) break;
  else{
  for(i=0;i<N;i++){
    cin>>box[i];
  }
  maxdayo=0;
  mindayo=1000;
  for(i=0;i<N;i++){
    total+=box[i];
    maxdayo=max(box[i],maxdayo);
    mindayo=min(box[i],mindayo);
  }
  total=total-maxdayo-mindayo;
  cout<<total/(N-2)<<endl;
  }
  total=0;
  }
  return 0;
}