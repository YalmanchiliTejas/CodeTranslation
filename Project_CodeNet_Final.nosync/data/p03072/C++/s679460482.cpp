#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,h[25],sum=1,wa;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>h[i];
  }
  for(int i=1; i<n; i++){
    wa=0;
    for(int j=0; j<i; j++){
      if(h[j]>h[i]){
	wa=1;
      }
    }
    if(wa==0){
      sum++;
    }
  }
  cout<<sum<<'\n';
  return 0;
}
