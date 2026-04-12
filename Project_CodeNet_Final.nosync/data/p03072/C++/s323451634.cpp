#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  int n;
  cin>>n;
  int h[n];
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  int ans=1;
  int max_h=h[0];
  for(int i=1;i<n;i++){
    if(h[i]>=max_h){
      ++ans;
      max_h=h[i];
    }
  }
  cout<<ans<<endl;


}