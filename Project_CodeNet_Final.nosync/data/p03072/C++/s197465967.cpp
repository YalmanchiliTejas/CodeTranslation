#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,h[20],c=0; cin>>n;
  for(int i=0;i<n;i++){
    cin>>h[i];
    bool f=true;
    for(int j=0;j<i;j++) if(h[i]<h[j]){f=false; break;}
    if(f) c++;
  }
  cout<<c;
}