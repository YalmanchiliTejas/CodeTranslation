#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  vector<int> b(n);
  for(int i=n-1;i>=0;i--){
    if(i%2==(n-1)%2){
      b[(n-1-i)/2]=a[i];
    }
    else{
      b[n-1-(n-1-i)/2]=a[i];
    }
  }
  for(int i=0;i<n;i++){
    cout<<b[i];
    if(i!=n-1) cout<<" ";
    else cout<<endl;
  }
  
  
  
  return 0;
}
