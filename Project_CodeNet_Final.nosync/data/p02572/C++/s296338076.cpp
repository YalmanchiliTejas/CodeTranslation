#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;  

int main(void){
  long long tmp,res=0;
  long long i,j,k;
  long long n;
  long long n_max=200010;
  long long a[n_max]={};
  long long b[n_max]={};
  long long mo=pow(10,9)+7;

  cin>>n;
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  b[n-1]=a[n-1]%mo;
  for(i=n-2;i>=0;i--){
    b[i]=(b[i+1]+a[i])%mo;
    //cout<<b[i]<<endl;
  }
  for(i=0;i<n-1;i++){
    res+=(a[i]%mo*b[i+1])%mo;
    res=res%mo;
    //cout<<(a[i]*b[i+1])%mo<<endl;;
  }
  cout<<res<<endl;
  return 0;
}