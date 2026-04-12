#include<bits/stdc++.h>
#define rep(i,n) for(int i=1; i<=n; i++)
using namespace std;
int main(){
  int n,l,r;
  while(cin >> n >> l >> r,n){
    int count=0;
    int a[51];
    a[0] = 0;
    rep(i,n) cin >> a[i];
    for(int x=l; x<=r; x++){
      bool flag=false;
      rep(i,n){
        if(x%a[i] == 0){
          flag = true;
          if(i%2 != 0) {
            count++;
          }
          break;
        }
      }
      if(flag == false && n%2 == 0) count++;
    }
    cout << count << endl;
  }
  return 0;
}


