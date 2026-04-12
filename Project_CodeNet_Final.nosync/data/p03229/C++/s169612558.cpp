#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n ;
  int a[n];
  
  for (int i = 0 ; i < n ; i++){
    cin >> a[i];
  }
  sort(a,a+n);

  int coe1[n];
  int coe2[n];

  coe1[0] = 1;
  coe2[0] = -1;

  for (int i = 1 ; i < n -1;i++ ){
    if (i % 2){
      coe1[i] = -2;
      coe2[i] = 2;
    }
    else {
      coe1[i] = 2;
      coe2[i] = -2;
    }
  }

  if (n % 2){
      coe1[n-1] = 1;
      coe2[n-1] = -1;
    }
  else {
      coe1[n-1] = -1;
      coe2[n-1] = 1;
  }

  sort(coe1,coe1+n);
  sort(coe2,coe2+n);

  long long sum1 = 0,sum2 = 0;
  
  for (int i=0 ; i < n ;i++){
    sum1 += coe1[i] * a[i];
    sum2 += coe2[i] * a[i];
  }

  long long ans = max(sum1,sum2);
 
  cout << ans <<  endl;
}
