#include <bits/stdc++.h>
using namespace std;
int main(){

  int n,q;
  cin>>n;
  vector <int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  cin>>q;
  for(int i=0;i<q;i++){
    int k;
    cin>>k;
    auto it=lower_bound(a.begin(),a.end(),k);
    cout<<distance(a.begin(),it)<<endl;
  }
  return 0;

}

