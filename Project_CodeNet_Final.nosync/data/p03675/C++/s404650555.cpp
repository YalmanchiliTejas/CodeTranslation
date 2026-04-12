#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  deque<int> d;
  for(int i=0;i<n;i++){
    if(i%2) d.push_front(a[i]);
    else d.push_back(a[i]);
  }
  if(n%2) reverse(d.begin(),d.end());
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<d[i];
  }
  cout<<endl;
  return 0;
}
