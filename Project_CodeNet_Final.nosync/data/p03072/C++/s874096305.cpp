#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  int m = 0;
  vector<int >a(n);
  int cnt = 0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(m <= a[i]){
       cnt++;
      m = a[i];
    }
  }
  cout<<cnt<<"\n";
  return 0;
}