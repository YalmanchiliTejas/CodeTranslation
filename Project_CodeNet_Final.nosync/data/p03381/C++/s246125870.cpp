#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int,int> P;

int n, ans[200005];
P X[200005];

signed main(){
  
  cin>>n;
  
  for(int i=0;i<n;i++){
    cin>>X[i].first;
    X[i].second = i;
  }
  
  sort(X, X+n);
  
  int l = n/2-1, r = n/2;  

  if( X[l].first == X[r].first ){
    
    for(int i=0;i<n;i++) cout<<X[l].first<<endl;
    
  }
  else{
    
    for(int i=0;i<n;i++){
      if( X[i].first <= X[l].first ) ans[X[i].second] = X[r].first;
      else ans[X[i].second] = X[l].first;
    }
    
    for(int i=0;i<n;i++){
      cout<<ans[i]<<endl;
    }
    
  }
  
  return 0;
}
