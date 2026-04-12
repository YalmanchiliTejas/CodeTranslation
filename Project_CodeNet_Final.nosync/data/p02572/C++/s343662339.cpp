#include<bits/stdc++.h>
using namespace std;

const long mod=1000000007;

int main(){
  int N;cin>>N;
  vector<long> A(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  long count=0;
  //N*Nから同じもの2乗を引いて2で割りたいけど、modは割り算に向いてない
  //逆から。
  queue<long> G;
  long allm=0;
  
  for(int i=N;i>1;i--){
    allm+=A.at(i-1);
    allm%=mod;
    G.push(allm);
  }
  for(int j=N-1;j>0;j--){
    long F=G.front();
    G.pop();
    F*=A.at(j-1);
    F %=mod;
    count+= F;
    count%=mod;
  }
  cout<<count<<endl;
    
}