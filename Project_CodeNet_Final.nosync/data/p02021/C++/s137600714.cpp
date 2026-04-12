#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a[100];
  cin>>n;
  for(int i=0;i<n;++i) cin>>a[i];
  int min=a[0],sum=a[0];
  for(int i=1;i<n;++i){
    sum+=a[i];
    if(sum/(i+1)<min) min=sum/(i+1);
  }
  cout<<min<<endl;
  return 0;
}

