#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  while(cin >> n){
    if(n==0)break;
    int ans[n][n];
    bool f[n][n];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        f[i][j]=true;
      }
    }
    ans[n/2+1][n/2]=1;
    f[n/2+1][n/2]=false;
    int nowi=n/2+1,nowj=n/2;
    for(int i=2;i<=n*n;i++){
      nowi++;
      nowj++;
      if(nowi==n){
        nowi=0;
      }
      if(nowj==n){
        nowj=0;
      }
      while(1){
        if(f[nowi][nowj]){
          f[nowi][nowj]=false;
          ans[nowi][nowj]=i;
          break;
        }else{
          nowi=((nowi+1==n)?0:nowi+1);
          nowj=((nowj)?nowj-1:n-1);
        }
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(ans[i][j]<1000){
          cout << " ";
        }
        if(ans[i][j]<100){
          cout << " ";
        }
        if(ans[i][j]<10){
          cout << " ";
        }
        cout << ans[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}

