#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N,count=0;
  cin>>N;
  vector<int>height,core;
  height.resize(N);
  core.resize(N);

  for(int i=0;i<N;i++)cin>>height[i];
  for(int t=0;t<N;t++){
    for(int j=0;j<t+1;j++)if(height[t+1]>=height[j])core[t]++;
    if(core[t]==t+1)count++;
  }
  cout<<count+1;
  return 0;
}
