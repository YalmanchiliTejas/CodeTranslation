#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int n;
  cin >>n;
  vector<int>h(n);
  rep(i,n)cin>>h[i];
  int takasa=h[0];
  int kotae=1;
  for(int i=1;i<n;i++){
    if(takasa<=h[i]&&h[i]>=h[i-1])kotae++;
    takasa=max(takasa,h[i]);
  } 
  cout<<kotae<<endl;
  return 0;
}
  