#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >>n>>k;
  long long count=0;
  for(int i=1;i<=n;i++){
    int shou=n/i;
    int amari=n%i;
    count+=max(i-k,0)*shou+max(amari-k+1,0);
    if(k==0)count--;
    //cout<<i<<" "<<shou<<" "<<amari<<" "<<count<<endl;
  }
  cout<<count<<endl;
  return 0;
}