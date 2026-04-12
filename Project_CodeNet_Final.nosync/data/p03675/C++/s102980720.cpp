#include <iostream>

using namespace std;

int main(){
  int n; cin >> n;
  int a[n+1],b[n+1];
  for(int i=1;i<=n;i++) cin >> a[i];
  //memorize previous index
  int p=n/2+1;
  b[p]=a[1];
  if(n%2==1){
    int idx=1;
    while(idx<=n-1){
      if(idx%2==0){
        b[p-idx]=a[idx+1];
        p=p-idx; idx++;
      }
      else{
        b[p+idx]=a[idx+1];
        p=p+idx; idx++;
      }
    }
  }else{
    int idx=1;
    while(idx<=n-1){
      if(idx%2==0){
        b[p+idx]=a[idx+1];
        p=p+idx; idx++;
      }
      else{
        b[p-idx]=a[idx+1];
        p=p-idx; idx++;
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(i==n) cout << b[n] << endl;
    else cout << b[i] << " ";
  }
}