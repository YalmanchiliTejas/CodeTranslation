#include <bits/stdc++.h>
using namespace std;
#define LOOP(val, times)   for(val = 0; val < (times); val++)
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  int i;
  LOOP(i,n){
    cin>>a[i];
  }
  int maxa=a[0];
  int ans=1;
  for(int i=1;i<n;i++){
    
    if(maxa<=a[i]){
      ans++;
    }
    
    if(maxa<a[i]){
      maxa=a[i];
    }
  }
  cout<<ans<<endl;
}

    
    