#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin>>n;
  vector<int> a(n);
  for (int i=0;i<n;++i) {
    cin>>a[i];
  }
  int cnt=1;
  int hst=a[0];
  for (int i=1;i<n;++i) {
    if (hst<=a[i]) {
      hst=a[i];
      cnt+=1;
    }
  }
  cout<<cnt<<endl;
}