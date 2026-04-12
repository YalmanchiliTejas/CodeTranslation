#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> x(n),y(n);
  for(int i=0; i<n; ++i) cin>>x[i];
  y=x; sort(y.begin(),y.end()); int z=(n-1)/2;
  for(int i=0; i<n; ++i){
    int m=lower_bound(y.begin(),y.end(),x[i])-y.begin();
    if(z<m) cout<<y[z]<<endl; else cout<<y[z+1]<<endl;
  }
  return 0;
}