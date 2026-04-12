#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;

main(){
  int n,q;
  cin>>n;
  vector<int>v(n+1);
  r(i,n)cin>>v[i];
  v[n]=1e9+7;
  cin>>q;
  while(q--){
    int a;
    cin>>a;
    int b=lower_bound(v.begin(),v.end(),a)-v.begin();
    cout<<b<<endl;
  }
}

