#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  int ans = 0;
  int maxh = 0;
  vector<int> h(n);
  
  for(int i=0;i<n;i++){
    cin>>h.at(i);
    maxh = max(maxh,h.at(i));
    if(h.at(i) >= maxh){
      ans++;
    }
  }
  cout<<ans<<endl;
}