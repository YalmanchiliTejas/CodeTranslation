#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin>>N;
  vector<uint64_t> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  uint64_t sum;
  uint64_t suma=0;
  uint64_t sums=0;
  for(int i=0;i<N;i++){
    suma+=a.at(i);
    suma=suma%2000000014;
  }
  suma=suma*suma;
  for(int i=0;i<N;i++){
    sums+=a.at(i)*a.at(i);
    sums=sums%2000000014;
  }
  if(suma>sums){
    sum=(suma-sums)/2;
  }else{
    sum=(sums-suma)/2;
  }
  sum=sum%1000000007;
  cout<<sum<<endl;
}
  