#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  int count=0;
  cin>>N;
  vector<int>height,core;
  core.resize(N);
  for(int i=0;i<N;i++){
    cin>>core[i];
    height.push_back(core[i]);
    if(i==0)continue;
    if(height[i]>=height[i-1])count++;
    sort(height.begin(),height.end());
  }
  cout<<count+1;
  return 0;
}
