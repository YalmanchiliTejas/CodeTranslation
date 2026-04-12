#include <bits/stdc++.h>
using namespace std;

long long int sum(long long int L,long long int X){
  if(X==1&&L!=0){
    return 0;
  }else{
  if(L==0){
    return 1;
  }else{
    if(X<=pow(2,L+1)-2){
      return sum(L-1,X-1);
    }else if(X==pow(2,L+1)-1){
      return pow(2,L);
    }else{
      return pow(2,L)+sum(L-1,X-pow(2,L+1)+1);
    }
  }
  }
}
int main(){
  long long int N,X;
  cin>>N>>X;
  cout<<sum(N,X)<<endl;
  
}