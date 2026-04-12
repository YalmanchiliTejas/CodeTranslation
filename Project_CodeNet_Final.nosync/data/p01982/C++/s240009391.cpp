#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)

int main(){
  int n, l, r, A[100], j;


  while(1){
    int count = 0;
    cin>>n>>l>>r;

    if(n == 0 && l == 0 && r ==0) break;

    for(int i = 1; i <= n; i++){
      cin>>A[i];
    }

    for(int i = l; i <= r; i++){//cout<<i<<endl;
      int f = 0;
      for(j = 1; j <= n; j++){
        if(i%A[j] == 0){
          if(j%2 == 1){
            f = 1;
          } else {
            f = 0;
          }
          break;
          }
      }
      if(j == n+1){
        if(n%2 == 0) f = 1;
        else  f = 0;
      }
      if(f == 1) count++;

    }

    cout<<count<<endl;
  }


  return 0;
}

