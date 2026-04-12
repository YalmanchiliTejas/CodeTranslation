#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  int n;
  int a[200005];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> b;
  for(int i=0;i<n;i+=2){
    b.push_back(a[i]);
  }
  reverse(b.begin(),b.end());
  for(int i=1;i<n;i+=2){
    b.push_back(a[i]);
  }
  if(n%2==0)reverse(b.begin(),b.end());
  for(int i=0;i<n-1;i++){
    cout<<b[i]<<" ";
  }
  cout<<b[n-1]<<"\n";
  return 0;
}
