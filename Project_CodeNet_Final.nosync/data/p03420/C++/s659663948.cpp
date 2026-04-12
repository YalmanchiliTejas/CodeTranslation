#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k; cin >> n >> k;
  long long int ans=0;
  if(k==0){cout << ((long long int) n * n) << endl; return 0;}
  for(int a=k+1;a<=n;a++){
    ans += (n/a) * (a - k) + (((n % a)>0) && ((n % a) - k >= 0) ? (n%a) - k + 1 : 0);
   // cout << a << ":" << (n/a) * (a - k) + (((n % a) > 0) && ((n % a) - k >= 0) ? (n%a) - k + 1 : 0) << endl;
  }
  
  cout << ans << endl;
  return 0;
}
  