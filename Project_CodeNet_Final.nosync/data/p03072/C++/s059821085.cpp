#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  vector<int> h;
  cin>>n;
  h.resize(n);
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  int sum=0;
  int max=0;
  for(int i=0;i<n;i++){
    if(max<=h[i])sum+=1;
    if(max<h[i])max=h[i];
  }
  cout<<sum<<endl;
  return 0;
}