#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,h[22],count=1,max;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  max=h[0];
  for(int i=1;i<n;i++){
    if(max<=h[i]){
      count++;
      max=h[i];
    }
  }
  cout<<count<<"\n";
  return 0;
}
