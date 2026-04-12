#include <bits/stdc++.h>
using namespace std;

vector<int64_t> v,vp;

int64_t countP(int L, int64_t x){
  if(L==0){
    return 1;
  }
  if(x<=1){
    return 0;
  }else if(x<=1+v.at(L-1)){
    return countP(L-1, x-1);
  }else if(x<=2+v.at(L-1)){
    return vp.at(L)/2+1;
  }else if(x<=2+v.at(L-1)*2){
    return vp.at(L)/2+1+countP(L-1, x-(2+v.at(L-1)));
  }else{
    return vp.at(L);
  }
}

int main(){
  int N;
  int64_t X;
  cin >> N >> X;
  v.resize(N+1);
  vp.resize(N+1);
  v.at(0)=1;
  vp.at(0)=1;
  for(int i=1;i<=N;i++){
    v.at(i)=v.at(i-1)*2+3;
    vp.at(i)=vp.at(i-1)*2+1;
  }
  cout << countP(N, X) << endl;
  return 0;
}
