#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main(){
  int n;
  cin >> n;

  int a[n];
  for (int i=0;i<n;i++){
    cin >> a[i];
  }
  
  long long ans=0,MOD = 1000000007,tmpSum=0,piledSum[n];

  //累積和
  piledSum[n-1] = a[n-1];
  //cout << piledSum[n-1] << endl;
  for (int i=n-2;i>=0;i--){
    piledSum[i] = piledSum[i+1] + a[i];
    //cout << piledSum[i] << endl;
  }

  
  for (int i=0;i<n-1;i++){
    
    //cout << "a[i]: " << a[i]%MOD << ", 累積和: " << piledSum[i+1] << ", ans:" << ans <<endl;
    ans += ((a[i]%MOD)*(piledSum[i+1]%MOD))%MOD;
    ans = ans%MOD;
  }

  cout << ans <<endl;
  
  return 0;
}