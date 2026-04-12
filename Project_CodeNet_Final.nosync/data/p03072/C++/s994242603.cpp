#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  int cnt=0,a=0;
  for(int i=0;i<n;i++){
    if(a<=h[i]){
      cnt++;
      a=h[i];
    }
  }
  cout<<cnt<<endl;
}