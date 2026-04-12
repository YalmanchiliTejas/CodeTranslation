#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n; cin >> n;
  long long a[n]={};
  
  for(long long i=0; i<n; i++){cin >> a[i];}
  sort(a,a+n);
  
  long long b[n] = {};
  b[0] = a[0];
  for(int i=1; i<n; i++) b[i] = b[i-1] + a[i];
  
  long long ans;
  
  if(n%2 == 0){
    ans = 2 * b[n-1] - 4 * b[n/2-1] - a[n/2] + a[n/2-1];
  }else{
    ans = 2 * b[n-1] - 4 * b[n/2] + a[n/2] + a[n/2-1];
    ans = max(ans, 2 * b[n-1] - 4 * b[n/2-1] - a[n/2] - a[n/2+1]);
  }
  
  cout << ans << endl; 
}