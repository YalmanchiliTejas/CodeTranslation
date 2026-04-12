#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)

int main() {
  int n;cin>>n;
  vector<int> s(n);
  rep(i,n) cin>>s[i];
  int max=0,counter=0;
  rep(i,n) {
    if (s[i]>=max) {
      max=s[i];
      counter++;
    }
  }
  cout<<counter<<endl;
}