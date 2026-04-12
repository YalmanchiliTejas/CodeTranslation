#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,X,Z=0;
  cin>>N>>X;
  vector<vector<int64_t>> p(N+1,vector<int64_t>(3));
  p.at(0).at(0)=1,p.at(0).at(1)=1;
  for(int64_t i=1;i<=N;i++){
    p.at(i).at(1)=p.at(i-1).at(1)*2+1;
    p.at(i).at(2)=p.at(i-1).at(2)*2+2;
    p.at(i).at(0)=p.at(i-1).at(0)*2+3;
  }
  while(X>0){
    X--;
    N--;
    if(X==p.at(N).at(0)){
      Z+=p.at(N).at(1);
      X=0;
    }
    else if(X>p.at(N).at(0)&&X<p.at(N).at(0)*2+1){
      Z+=1+p.at(N).at(1);
      X-=p.at(N).at(0)+1;
    }
    
    else if(X==p.at(N).at(0)*2+2||X==p.at(N).at(0)*2+1){
      Z+=p.at(N).at(1)*2+1;
      X=0;
    }
  }
  cout<<Z<<endl;
    
}