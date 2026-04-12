#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  int n;
  cin>>n;
  int h[25];
  for (int i=0; i<n; i++) {
    cin>>h[i];
  }

  int ans=0;
  bool flag;
  for (int i=0; i<n; i++) {
    flag=true;
    for (int j=0; j<i; j++) {
      if (h[i]<h[j]) flag=false;
    }
    if (flag) ans++;
  }
  cout<<ans<<endl;
  return 0;
}

