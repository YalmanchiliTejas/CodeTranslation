#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;

int main() {
  int n; cin>>n;
  int a[n];
  deque<int> v;
  rep(i,n) cin>>a[i];
  
  rep(i,n){
    int p=lower_bound(v.begin(),v.end(),a[i])-v.begin();
    if(p==0){
      v.push_front(a[i]);
    }
    else{
      v[p-1]=a[i];
    }
  }
  
  cout<<v.size()<<endl;
    
}