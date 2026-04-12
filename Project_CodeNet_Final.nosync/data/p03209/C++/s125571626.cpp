#include<iostream>
using namespace std;

long long patty[55];
long long bun[55];

long long burger(long long n,long long k);
int main(){
  long long n,k;
  cin>>n>>k;
  patty[0]=1;
  bun[0]=0;
  for(long long i=1;i<=n;i++){
    patty[i]=patty[i-1]*2+1;
    bun[i]=bun[i-1]*2+2;
  }
  
  cout<<burger(n,k)<<endl;
  return(0);
}

long long burger(long long n,long long k){
  if(k==0){
    return(0);
  }
  if(n==0){
    return(1);
  }
  
  if(k <= (patty[n]+bun[n])/2){
    return(burger(n-1,k-1));
  }else if(k > (patty[n]+bun[n])/2+1){
    return(patty[n-1] + 1 + burger(n-1,k-((patty[n]+bun[n])/2+1)));
  }
  return(patty[n-1] + 1);
}
