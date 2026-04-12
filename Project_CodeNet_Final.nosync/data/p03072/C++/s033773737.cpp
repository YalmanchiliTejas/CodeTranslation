#include<bits/stdc++.h>
 using namespace std;
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;++i) {
    cin>>a[i];
  }
  int maxm = a[0], c=1;
  for(int i=1;i<n;++i) {
    maxm = max(maxm, a[i]);
    if(maxm == a[i]) {
      c++;
    }
  }
  cout<<c;
  return 0;
}