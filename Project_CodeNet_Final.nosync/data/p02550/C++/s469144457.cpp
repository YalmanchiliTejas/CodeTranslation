#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,X,M,Z=0,A=0;
  cin>>N>>X>>M;
  vector<int64_t> p(M);
  vector<int64_t> q;
  for(int i=1;i<=N;i++){
    if(p[X]){
      A=p[X];
      break;
    }
    p[X]=i;
    q.push_back(X);
    Z+=X;
    X*=X;
    X%=M;
  }
  if(A){
    A--;
    int64_t L=q.size();
    int64_t R=(N-L)/(L-A),S=(N-L)%(L-A),K=0;
    for(int i=0;i<L-A;i++){
      if(i==S){
        Z+=K;
      }
      K+=q[A+i];
    }
    Z+=R*K;
  }
  cout<<Z<<endl;
}