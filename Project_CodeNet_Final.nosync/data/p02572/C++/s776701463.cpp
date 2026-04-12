#include <bits/stdc++.h>
using namespace std;
long long int m=1000000007;
int main(){
  int n;
  cin>>n;
  long long int* a =new long long int[n];
  long long int s=0,t=0;
  for(int i=0;i<n;i++){
   	cin>>a[i];
    s=(s+a[i])%m;
    t=(t+(a[i]*a[i])%m)%m;
  }
  s=(s*s)%m;
  long long int ans=(s+m-t)%m;
  ans=(ans*(500000004))%m;
  cout<<ans<<endl;
}