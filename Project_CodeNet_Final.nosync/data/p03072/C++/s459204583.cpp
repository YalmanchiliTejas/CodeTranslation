#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
  int count=0;
  int flag=0;
  int N;
  cin>>N;
  vector<int>X(N);
  rep(i,N){
    cin>>X[i];
  }
  rep(i,N){
    rep(j,i){
      if(X[j]>X[i]){
        flag++;
      }
    }
      if(flag==0){
        count++;
      }
      flag=0;
    
  }
  cout<<count;
}
