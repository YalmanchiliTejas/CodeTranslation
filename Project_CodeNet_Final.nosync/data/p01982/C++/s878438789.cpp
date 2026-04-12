#include<iostream>
using namespace std;
int main(){
  int n,l,r,cnt=0,ind;
  cin >> n>>l>>r;
  while(n!=0){
    int a[n];
    cnt=0;
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    for(int i=l;i<=r;i++){
      ind=-1;
      for(int j=0;j<n;j++){
        if(i%a[j]==0){
          ind=j+1;
          break;
        }
      }
      if(ind==-1){
        if(n%2==0)cnt++;
      }else{
        if(ind%2!=0)cnt++;
      }
    }
    cout << cnt << endl;
    cin >> n >> l >> r;
  }
}

