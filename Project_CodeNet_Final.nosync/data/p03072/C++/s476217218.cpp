#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
  int n,ans=0,s=0;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      if(a[j]<=a[i]){
        s++;
      }
    }
    if(s==i+1){
      ans++;
    }
    s=0;
  }
  cout<<ans<<endl;
}
